# gba-hello-world
Modified "hello world" example code to display video on the GBA. Video is converted into GBA format using png2gba, example code then imports those converted files as header files to create video on the GBA.
Code is a proof of concept and intends to demonstrate the ability of png2gba to create GBA videos. 
> The [releases](https://github.com/Treagle350/GBA_video_example/releases) section of this repo contains a test video converted to GBA format.

GBA videos created by png2gba are currently unoptimized and bloated which greatly reduces playtime of videos.

Png2gba fork supporting video conversion to GBA format is currently located at (pending merge request) : 

https://github.com/Treagle350/png2gba

Original master of png2gba is located at : 

https://github.com/IanFinlayson/png2gba

## Basic instructions on video conversion
I used ffmpeg to convert the video to sliced png files that can then be displayed on the GBA :

(currently video conversion is unoptimized so length of video is reduced to address that)
(Proof of concept tries to use -p flag so the amount of colors had to be reduced, lazy way to do that is setting the hue to low saturation. Downside to that is that everything becomes red.)

> __ffmpeg -y -i vid.mp4 -vf "scale=240:160, fps=15, hue=s=0" -t 00:00:30 out%09d.png__

I then used the png2gba utility to convert the png files from earlier to header files which the GBA can read and display :

> __./png2gba -o vid.h -p out*.png__

### Video source :
The video used here is the ISS 4K Crew Earth Observations from NASA

https://images.nasa.gov/details-ISS%204K%20Crew%20Earth%20Observations

# Compile
*"The hardest part is getting started"*

1. **Install [devkitPRO's pacman](https://github.com/devkitPro/pacman/releases/latest)**. 

DevkitPRO's pacman is a package manager just like any other but built exclusively for retro gaming development built by the devkitPRO team.

2. **Install the GBA rules with pacman**. 

Once pacman is intalled you can run the following command:

```
$ sudo dkp-pacman -S gba-dev
```

3. **Run the Makefile**

Run the following command at the root folder of this repo and it will compile the .gba rom file.
```
$ make
```

For windows you can check out the oficial [devkitPRO documentation](https://devkitpro.org/wiki/devkitPro_pacman) (sorry)


# Resources
- [VisualBoy Advance GBA emulator](https://sourceforge.net/projects/vba/files/)
- [Writing a GBA game](https://www.reinterpretcast.com/writing-a-game-boy-advance-game)
- [TONC's guide for GBA development](http://www.coranac.com/tonc/text/toc.htm)
- [GBA examples](https://github.com/devkitPro/gba-examples)


