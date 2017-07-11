/*
 * Gets created by light_globe spell
 * Created by Zaxan@Haven
 * 20th of February, 1997
 */

#include <lib.h>
inherit LIB_ITEM;
int Life;
void destme();
int SetLife(int);
int GetLife();

static void create() {
  item::create();
	SetKeyName("halo");
  SetProperty("magic", "This is a halo of musical talent.");
	SetId( ({ "halo" }) );
	SetAdjectives("magical");
	SetShort("a halo");
	SetInvis(1);
  SetMass(0);
  SetValue(0);
	SetRadiantLight(20);
  set_heart_beat(1);
  SetLife(100);
  SetPreventGet("");
  SetPreventDrop("");
  SetRetainOnDeath(1);
}

void heart_beat() {
  Life--;
  if (!Life) destme();
  }

void destme() {
	if (environment(this_object())) {
		message("system",
		  "The effects of your bright and cheerful song have worn off.",
			  environment(this_object()) );
		}
        eventDestruct();
}

int SetLife(int x) { return Life = x; }

int GetLife() { return Life; }

string GetAffectLong(object u) {
  	return  "A shining halo of light seems to eminate from "
  	  "the smile on " + possessive(environment()) + " face.";
}
