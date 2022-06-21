# projectACM

Project's Title : ASCII Art Generator

Project Description : Making a video using ASCII characters

Run the project in terminal using the command - python3 asciiVideo.py

Project theory - Converting a video into ASCII charactered video using python.

So the code goes like this - 

Firstly we use OpenCV and Pillow libraries for implementing this program.

To begin with we use a function called videotoFrames() where we're taking a video file as an input and splitting the video into many frames and assigning names to each of the frame and also we're getting the size(height and width of the frame) of each of the frames.

Now using another function called imgtoASCII() we get the frames that are splitted in the previous function and assign characters to each of the pixel shades ranging from 0 - 255 in the greyscale image for every row and every column of a single frame. The characters are assigned according to intensity of the shade. 

Next in the stringtoImage() function we pass the frames that are converted as Character codes in the previous function and the corressponding frame names as arguments. In this function firstly we create a blank image and add the texts that are stored as strings in the previous function to each of the new images that we want to create. We also provide the font of our choice and also the background color that we want in our final output video. Atlast we are saving the images in the local disk.

Now, the only process that's remaining is to stack all the images together to make it into a single ASCII video. For this we use imagesToMovie() function where we pass filenames and the video name of our choice as arguments. Here the function is reading each of the frame and writes every frame into the video. Finally we save the video in our local disk !

All the functions are called from the main() function.

Learnings from the project :
1. How images are stored in a computer memory.
2. More knowledge on ASCII charcters.
3. To convert an colored image into greyscale image using python.
4. To convert a video into ASCII encoded strings video using python

Video demo of the project : Google drive link - 

References used while making the project: https://www.analyticsvidhya.com/blog/2021/03/grayscale-and-rgb-format-for-storing-images/
https://techtutorialsx.com/2021/04/29/python-opencv-splitting-video-frames/
