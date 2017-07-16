#include <lib.h>
inherit LIB_ROOM;
 
static void create() {
   room::create();
   SetShort("Immortal Playpen");
   SetLong("This peculiar playpen is basically a platform of wood "
           "stuck into thin air.  A large tree is growing in the "
           "exact center of it, pine cones, bugs, and all.  Walls "
           "like those of a normal playpen, only maybe around "
           "ten times the size, rise up from the edges of the huge "
           "platform.  A blue glow above shows the presence of "
           "field that blocks the movement of all beings:  mortal, "
           "and immortal.");
   SetItems( ([
                ({ "immortal playpen","playpen","peculiar playpen",
                   "platform","wood","platform of wood",
                   "wooden platform","huge platform" }) : (: GetLong :),
                ({ "large tree","tree","exact center","center",
                   "pine cones","cones","pine cone","cone","bug",
                   "bugs" }) :
                   "The huge tree is indescribable in it's magnitude, "
                   "it reminds one of the trees in Soleil.",
                ({ "blue glow","glow" }) :
                   "The glow wards off all life.  A bug tries to "
                   "fly past it as you observe, and is dissolved into "
                   "dust.",
                ({ "huge walls","wall","wall" }) :
                   "The walls are rather like that of a normal playpen, "
                   "but much too large and imposing to be very close to "
                   "the same.  There is a small label on one.",
                ({ "small label","label" }) :
                   "The label reads:  \n"
                   "Wlkm to the Immortal Playpen.  \n"
                   "You'll be here for a while.  \n"
                   "Sit back, relax, eat a few \n"
                   "cookies, snuggle the furries \n"
                   "into submition, hold the popples \n"
                   "and pet those shaggy dogs. \n\n"
                   "Enjoy! \n"
           ]) );
   SetObviousExits("none");
   SetInventory( ([
                    "/realms/amelia/old/obj/bottle" : 5,
                    "/realms/amelia/old/obj/cookies" : 10,
                    "/realms/amelia/old/obj/cookieg" : 10,
                    "/realms/amelia/old/obj/toy" : 10,
               ]) );
   SetProperty("no teleport",1);
   SetProperty("no magic",1);
}
 
int CanRelease() {
   if(this_player()->GetKeyName()=="amelia") return 1;
   if(!archp(this_player())) return 0;
   else return 1;
}
 
void init() {
   ::init();
   if(userp(this_player())&&!immortalp(this_player())) {
      this_player()->eventMove("/domains/heaven/room/clouda");
   }
   if(!securep(this_player())) {
      all_inventory(this_player())->eventDestruct();
   }
   add_action("dest","dest");
   add_action("call","call");
   add_action("update","update");
   add_action("clone","clone");
   add_action("home","home");
   add_action("move","move");
   add_action("eval","eval");
   add_action("ed","ed");
   add_action("trans","trans");
   add_action("duc","dest");
   add_action("force","force");
   add_action("cd","cd");
   add_action("assume","assume");
   add_action("rm","rm");
}

int rm() {
   if(!securep(this_player())) return 1;
   return 0;
}

int assume() {
   if(!securep(this_player())) return 1;
   else return 0;
}

int cd() {
   if(!securep(this_player())) return 1;
   else return 0;
}

int force() {
   if(!securep(this_player())) return 1;
   else return 0;
}
 
int dest() {
   if(!securep(this_player())) return 1;
   else return 0;
}
 
int call() {
   if(!securep(this_player())) return 1;
   else return 0;
}
 
int update() {
   if(!securep(this_player())) return 1;
   else return 0;
}
 
int clone() {
   if(!securep(this_player())) return 1;
   else return 0;
}
 
int eval() {
   if(!securep(this_player())) return 1;
   else return 0;
}
 
int ed() {
   if(!securep(this_player())) return 1;
   else return 0;
}
 
int trans() {
   if(!securep(this_player())) return 1;
   else return 0;
}
int move() {
   if(!securep(this_player())) return 1;
   else return 0;
}

int home() {
   if(!securep(this_player())) return 1;
   else return 0;
}
