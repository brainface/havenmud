/*    /lib/comp/container.c
 *    From the Dead Souls LPC Library
 *    Object inherited by all objects with inventories
 *    Created by Descartes of Borg 940212
 *    Version: @(#) container.c 1.3@(#)
 *    Last modified: 96/12/31
 */

#include <lib.h>

inherit LIB_LOOK_IN;
inherit LIB_RADIANCE;

varargs int GetRadiantLight(int ambient) {
    int r = radiance::GetRadiantLight();
    int o = GetOpacity();
    int y;
      
    foreach(object ob in all_inventory()) {
	     r += ob->GetRadiantLight(ambient);
    }
    
    return r;
}

int GetHeat() {
  int r = 0;
  foreach(object ob in all_inventory()) {
    r += ob->GetHeat();
  }
  return r;
}
  
int CanReceive(object ob) {
	 if (sizeof(all_inventory()) > 150) return 0;
   return 1;
}

int CanRelease(object ob) {
    return 1;
}

int eventReceiveObject(object ob) {
    return !(!previous_object());
}

int eventReleaseObject(object ob) {
    return !(!previous_object());
}
