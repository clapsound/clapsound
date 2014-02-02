#include <fstream>
#include <iostream>
#include <allegro.h>

using namespace std;

const int scrx = 640;
const int scry = 480;
 
int main(int argc, char* argv[]) {
  if (allegro_init() != 0) {
    allegro_message("Cannot initalize Allegro.\n");
    return 1;
  }
 
  //Set the window title when in a GUI environment
  set_window_title("Hello World");
 
  if (install_keyboard()) {
    allegro_message("Cannot initalize keyboard input.\n");
    return 1;
  }
 
  //set graphics mode, trying all acceptable depths
  set_color_depth(32);
  if (set_gfx_mode(GFX_AUTODETECT, scrx, scry, 0, 0)) {
    set_color_depth(24);
    if (set_gfx_mode(GFX_AUTODETECT, scrx, scry, 0, 0)) {
      set_color_depth(16);
      if (set_gfx_mode(GFX_AUTODETECT, scrx, scry, 0, 0)) {
        set_color_depth(15);
        if (set_gfx_mode(GFX_AUTODETECT, scrx, scry, 0, 0)) {
          allegro_message("Video Error: %s.\n", allegro_error);
          return 1;
        }
      }
    }
  }
 
	ifstream ampl;
	ampl.open("file.txt");
	string n;

	ampl>>n;

	ampl.close();
	string number=(int) n;
  //set text background color to bright blue
  text_mode(makecol(0, 0, 255));
 
  //prints yellow "Hello World!!!" in middle of screen
  textout_centre(screen, font, number.c_str(), scrx/2,
                 scry/2, makecol(255, 255, 0));
 
line(screen, 0,0,480,480,makecol(255, 0, 5));

  //Wait for a key to be pressed
  while (!keypressed()) {}
 
  return 0;
  //Allegro will automatically deinitalize itself on exit
}
END_OF_MAIN()
