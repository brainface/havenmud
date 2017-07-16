#include <lib.h>
#include <damage_types.h>
inherit LIB_VEHICLE;

int SetDestTime(int yeah);
void destalmost();
void destme();
int GetDestTime();
int DestTime = 0;

static void create() {
   vehicle::create();
   SetKeyName("tunnel");
   SetShort("a tunnel in the ground");
   SetId( ({ "tunnel" }) );
   SetLong("The tunnel goes deep down into the depths of the "
           "earth.");
   SetPreventGet("Get a tunnel?  Are you crazy?");
   set_heart_beat(1);
}

void init() {
   ::init();
   message("system","You are whisked through the tunnel at "
           "breakneck speeds and finally arrive in Ditmar.",
           this_player());
   this_player()->eventMove("/domains/ditmar/room/atgates");
}

void heart_beat() {
   if(!DestTime) {
      destalmost();
      set_heart_beat(0);
      call_out( (: destme() :), 10);
   }
   DestTime--;
}

void destalmost() {
   message("system","The tunnel shrinks slightly.",
           environment(this_object()));
   return;
}

void destme() {
   message("sytem","The tunnel closes completely.",
           environment(this_object()));
   return;
}

int SetDestTime(int yeah) {
   return DestTime = yeah;
}

int GetDestTime() {
   return DestTime;
}

