#include <lib.h>
inherit LIB_DAEMON;

mixed cmd(string args) {
int x, cost, xpmod;

  while(x < 500) {

    switch(x + 1) {
      case 0..10:
        cost  = 0;
        xpmod = 1;
        break;
      case 11..24:
        cost  = 500;
        xpmod = 2;
        break;
      case 25..49:
        cost  = 2500;
        xpmod = 5;
        break;
      case 50..99:
        cost  = 10000;
        xpmod = 10;
        break;
      case 100..249:
        cost  = 25000;
        xpmod = 25;
        break;
      case 250..299:
        cost  = 100000;
        xpmod = 50;
        break;
      case 300..999:
        cost  = 1000000;
        xpmod = 100;
        break;
    }
  x++;
    write_file("/log/players/xpcosts", "XPCost for level " + x + " == " + (xpmod * x * 500) + ".\n");
  }
  return 1;
}