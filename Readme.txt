1 Run gcc ur.c -o ur
2 Run gcc us.c -o us
3 Run gcc up.c -o up
4 Syntax for running ur : ./ur [PORTNO]
5 Syntax for running us : ./us [PORTNO] [Filename.format] [Max_limit_of_data] 
5 up is menu driven program with following options
-------------------------------------------------------------------------
Menu for your reference
***Menu***
1.Check Messages | Syntax : ./up 1 
2.Send Message   | Syntax : ./up 2 (Size limit[Bytes]))
3.Exit           | Syntax : ./up 3
-------------------------------------------------------------------------
6 You can just type ./up to see menu command
7 If suppose a video file(.mp4) is sent to system listening on port no. 4000 then file received will be 4000.mp4. Similarly for image and
audio it will be 4000.jpg and 4000.mp3 respectively.
7 After Seeing menu you can do desired operations
8 ./up 1 requires PORTNO
9 ./up 2 will ask you for [PORTNO](the port no. of system which will receive the data),the [Filename.format(video,audio,image)](Ex. Pixels.mp4) and [Max_limit](The max_limit of data that can be sent at a time)
10 ./up 3 will Exit the program
