1. fswebcam -d /dev/video0 ex5_1.jpg --resolution 640x480

2. fswebcam -d /dev/video0 test.jpg --resolution 640x480 --delay 5 

3. fswebcam -d /dev/video0 test.jpg --resolution 640x480 --skip 20

sudo ./mjpg_streamer -i "./input_uvc.so -f 10 -r 320x240 -d /dev/video0 -y -n" -o "./output_http.so -w ./www -p 8080"

