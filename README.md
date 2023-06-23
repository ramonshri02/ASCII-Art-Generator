# Project Name: Asciify : ASCII Art Generator
## Project Description

The ASCII Image Converter is a Python-based project that allows you to convert images into ASCII art and display them in your terminal. ASCII (American Standard Code for Information Interchange) is a widely used character encoding format that represents text and symbols using a set of 128 standard characters.

This project takes advantage of ASCII characters to create a visual representation of images using various shades of gray. By mapping different ASCII characters to different levels of brightness, the converter can transform an image into a visually similar ASCII art representation.

## Usage
* Place the image file you want to convert into the project directory.
* Run the ascii_image_converter.py script:
python ascii_image_converter.py
* Follow the on-screen instructions to select the image file and adjust conversion settings.
* Once the conversion is complete, the ASCII art will be displayed in your terminal.
* Optionally, you can save the ASCII art as a text file by entering 'Y' when prompted.

The program uses the OpenCV and Pillow libraries to convert a video into an ASCII art video. It consists of the following functions:

videotoFrames(video_file): This function takes a video file as input and splits it into individual frames. Each frame is assigned a name, and the height and width of the frame are obtained.

imgtoASCII(frame, frame_name): This function converts each frame into ASCII art. It assigns characters to each pixel shade in the grayscale image based on intensity. The resulting ASCII art frames are stored as character codes.

stringtoImage(ascii_frames, frame_names): This function creates new images using the ASCII art frames generated in the previous step. It adds the ASCII art as text to each image, allowing customization of font and background color. The images are saved to the local disk.

imagesToMovie(filenames, video_name): This function stacks the ASCII art images together to create a single ASCII art video. It reads each frame and writes them into a video file. The resulting video is saved to the local disk.
All these functions are called from the main() function, which orchestrates the entire process.

By combining these functions, the program takes a video file as input, converts it into ASCII art frames, creates ASCII art images, and finally generates an ASCII art video.

Learnings from the project :
1. How images are stored in a computer memory.
2. More knowledge on ASCII charcters.
3. To convert an colored image into greyscale image using python.
4. To convert a video into ASCII encoded strings video using python

Video demo of the project : Google drive link - https://drive.google.com/file/d/1iiy0Ydc760pnuriVbT-YVBwMrDyLGrt5/view?usp=sharing

References used while making the project: https://www.analyticsvidhya.com/blog/2021/03/grayscale-and-rgb-format-for-storing-images/
https://techtutorialsx.com/2021/04/29/python-opencv-splitting-video-frames/
