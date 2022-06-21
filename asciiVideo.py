from turtle import width
import cv2
import os
import numpy as np
from PIL import Image, ImageDraw, ImageOps, ImageFont

sourceFPS = 0

# Converting the Input Video into frames
def videoToFrames(vidFile):
	fileList = []																# Empty list to store file names and track order
	maxWidth = 160																# Specify max. width of resized frames
	global sourceFPS															
	vidcap = cv2.VideoCapture("Video1.mp4")									    # Accessing the source video file
	sourceFPS = vidcap.get(cv2.CAP_PROP_FPS)									# Determine the FPS of the video file
	success,image = vidcap.read()												# Read the first frame of the video
	count = 0																	# Initialize a counter to track frame numbers
	while success:																# While successfully reading frames
		width, height, _ = image.shape											# Get the frame dimensions
		shrinkRatio = width / maxWidth											# Get the ratio to shrink by to make it the max Width
		image = cv2.resize(image, (int(height/shrinkRatio),int(width/shrinkRatio)))	# Resize the frame
		image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)							# Convert frame to greyscale
		cv2.imwrite("Frame%d.jpg" % count, image)     							# Save frame as JPG file
		fileList.append("Frame%d.jpg" % count)									# Append filename to list
		success,image = vidcap.read()											# Read the next frame
		print("Frame " + str(count) + " successfully read")						
		count += 1																#increment the counter
	return(fileList)

# Converting frames into ASCII Art
def imgToAscii(imgFile):
    divisor = 3.642857142857143                                                 # 255 shades of grey per pixel.  Div by this to assign 255 shades to one ASCII character
    maxWidth = 160                                                              # Maximum width of resized image
    asciiArt = " "                                                              # Output string 

    # Greyscale to ASCII conversion
    greyscaleChars = {
		"70" : "$","69" : "@","68" : "B","67" : "%","66" : "8","65" : "&","64" : "W","63" : "M","62" : "#","61" : "*","60" : "o","59" : "a","58" : "h","57" : "k","56" : "b","55" : "d","54" : "p","53" : "q","52" : "w",
		"51" : "m","50" : "Z","49" : "O","48" : "0","47" : "Q","46" : "L","45" : "C","44" : "J","43" : "U","42" : "Y","41" : "X","40" : "z","39" : "c","38" : "v","37" : "u","36" : "n","35" : "x","34" : "r","33" : "j",
		"32" : "f","31" : "t","30" : "/","29" : "\\","28" : "|","27" : "(","26" : ")","25" : "1","24" : "{","23" : "}","22" : "[","21" : "]","20" : "?","19" : "-","18" : "_","17" : "+","16" : "~","15" : "<","14" : ">",
		"13" : "i","12" : "!","11" : "l","10" : "I","9" : ";","8" : ":","7" : ",","6" : "\"","5" : "^","4" : "`","3" : "'","2" : ".","1" :  " "	,"0" :  " "
		}

    img = Image.open(imgFile)	                                                # Open the image file
    greyImg = img.convert("L")                                                  # Convert image to greyscaleChars
    size = greyImg.size	                                                        # Get size of image
    shrinkRatio = size[0] / maxWidth                                            # Get the ratio to shrink by to make it the max Width
    greyImg = greyImg.resize((int(size[0]/shrinkRatio), int(size[1]/shrinkRatio)))		#Resize the image																					
    size = greyImg.size                                                         # Get new size of the image
    for y in range (0,size[1]):	                                                # For every row 0,0 is the top left.
        for x in range (0,size[0]):	                                            # For every column
            pix = int(greyImg.getpixel((x,y)))                                  # Get the pixel shade (0 - 255)
            pix = int(pix / divisor)		                                    # Assign pixel shade to an ascii character						
            asciiArt = 	asciiArt + greyscaleChars[str(pix)]                     # Create the output string
        asciiArt = asciiArt + " \n "                                            # New line after all columns in the row are completed
    return asciiArt


def stringToImage(imgText, width, height, imgName):
    # Making a new Image using PIL
    img = Image.new("L", (width, height))                                       # Create a blank image with the specified dimensions
    draw = ImageDraw.Draw(img)                                                  # Create a draw object
    font = ImageFont.truetype("DejaVuSansMono.ttf", size=20)                    # Create a font object
    draw.multiline_text((0,0), str(imgText), fill= (255), font=font)            # Add the text to the image
    img.save(imgName)                                                           # Return the fileList

# Combining all frames to make a ASCII Video !!
def imagesToMovie(fileList, videoname):
    global sourceFPS
    frameRate = sourceFPS
    frame = cv2.imread(fileList[0])                                             # Read the first frame from the fileList
    height, width, layers = frame.shape                                         # Get the frame dimensions
    video = cv2.VideoWriter(videoname, cv2.VideoWriter_fourcc('M','J','P','G'), frameRate, (width,height))  # Create a new video

    for f in fileList:                                                          # For every image in the fileList
        frame = cv2.imread(f)                                                   # Read the frame
        video.write(frame)                                                      # Write the frame to the video
    video.release()                                                             # Save the video

def main():
	horiMultiplyer = 10														    # Pixel width for a single character
	vertMultiplyer = 18														    # Pixel height for a single character
	asciiFileNames = []														    # List of images converted to ascii

	fileNames = videoToFrames("TEST.MOV")								        # Call process to convert video into frames and store file names

	for n in fileNames:														    # For every file name
		art = (imgToAscii(n))												    # Convert image to a string of ASCII characters
		artList = art.split("\n")											    # Split based on lines to determine image dimensions
		imgHeight = int(len(artList) * vertMultiplyer)						    # Get number of rows
		imgWidth = int(len(artList[0]) * horiMultiplyer)					    # Get characters per line
		asciiFileNames.append("ASCII " + n)										# Add string to ascii image file name to list
		stringToImage(art, imgWidth,imgHeight, ("ASCII " + n))					# Convert string to ascii image
		print("Converted:\t" + n)											
		os.remove(n)														    # Cleanup the original greyscale image

	imagesToMovie(asciiFileNames, "ASCII_Video1.avi")							# Convert images into movie
					

	for n in asciiFileNames:												    # Cleanup ASCII images
		os.remove(n)														    # Remove the file


if __name__ == "__main__":
	main()
