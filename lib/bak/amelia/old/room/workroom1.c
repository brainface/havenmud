#include <lib.h>
inherit LIB_ROOM;
 
int StopIt();
 
static void create() {
  room::create();
  SetShort("%^MAGENTA%^Immortal Playpen%^RESET%^");
  SetLong("%^CYAN%^This peculiar playpen is basically a platform of wood "
    "stuck into thin air.  A large tree is growing in the exact "
    "center of it, pine cones, bugs, and all.  Walls like those of "
    "a normal playpen, only maybe around ten times the size, rise "
    "up from the edges of the huge platform.  A blue glow above "
    "shows the presence of field that blocks the movement of all "
    "beings:  mortal, and immortal.  There is a small label.  "
    "Maybe you should read it.%^RESET%^");
  SetItems( ([
    ({"immortal playpen","playpen","peculiar playpen","platform",
      "wood","platform of wood","wooden platform",
      "huge platform"}) : (: GetLong :),
    ({"large tree","tree","exact center","center","pine cones","cones",
      "pine cone","cone","bug","bugs" }) : "The huge tree is "
      "indescribable in it's magnitude, it reminds one of the trees "
      "in Soleil.",
    ({ "blue glow","glow" }) :
      "The glow wards off all life.  A bug tries to fly past it as "
      "you observe, and is dissolved into dust.",
    ({ "huge walls","wall","wall" }) :
      "The walls are rather like that of a normal playpen, but much "
      "too large and imposing to be very close to the same.  There "
      "is a small label on one.",
    ({ "small label","label" }) :
      "The label reads:  \n"
      "Wlkm to the Immortal Playpen.  You'll be here for a while.\n"
      "Sit back, relax, eat a few cookies, snuggle the furries \n"
      "into submition, hold the popples and pet those shaggy dogs. \n"
      "Enjoy! \n"
  ]) );
  SetObviousExits("%^ORANGE%^none%^RESET%^");
  AddExit("down","workroom",(:CanRelease:));
  SetGravity(2.0);
  SetInventory( ([
    "/realms/gabriel/npc/thing" : 10,
    "/realms/gabriel/npc/popple" : 10,
    "/realms/gabriel/obj/food/cookieg" : 3,
    "/realms/gabriel/obj/food/cookiecc" : 3,
    "/realms/gabriel/obj/food/cookies" : 3,
    "/realms/gabriel/obj/food/bottle" : 5,
    "/realms/gabriel/obj/toys/toy" : 7,
    "/realms/gabriel/obj/toys/bubble" : 15,
    "/realms/gabriel/obj/toys/spliff" : 2,
  ]) );
  SetProperty("no teleport",1);
  SetProperty("no magic",1);
}
 
int CanRelease() {
   if(!userp(this_player())) return 1;
   if(this_player()->GetKeyName()=="gabriel") return 1;
   if(!securep(this_player())) return 0;
   else return 1;
}
 
void init() 
{
  ::init();
  if(!securep(this_player())) 
  {
    if(this_player()->GetCapName() != "Gabriel") 
    {
      deep_inventory(this_player())->eventDestruct();
    }
  }
  this_player()->eventForce("save");
  add_action((: StopIt :),"dest");
  add_action((: StopIt :),"call");
  add_action((: StopIt :),"update");
  add_action((: StopIt :),"clone");
  add_action((: StopIt :),"eval");
  add_action((: StopIt :),"ed");
  add_action((: StopIt :),"trans");
  add_action((: StopIt :),"duc");
  add_action((: StopIt :),"ls");
  add_action((: StopIt :),"cp");
  add_action((: StopIt :),"mv");
  add_action((: StopIt :),"rm");
  add_action((: StopIt :),"force");
  add_action((: StopIt :),"cd");
  add_action((: StopIt :),"assume");
  add_action((: StopIt :),"home");
  add_action((: StopIt :),"quit");
  add_action((: StopIt :),"zap");
  add_action((: StopIt :),"more");
  add_action((: StopIt :),"grep");
  add_action((: StopIt :),"spew");
  add_action((: StopIt :),"tell");
  add_action((: StopIt :),"ooc");
  add_action((: StopIt :),"imm");
  add_action((: StopIt :),"rp");
  add_action((: StopIt :),"reports");
  add_action((: StopIt :),"error");
  add_action((: StopIt :),"magic");
  add_action((: StopIt :),"prayer");
  add_action((: StopIt :),"code");
}
 
int StopIt() {
   if(this_player()->GetKeyName()=="gabriel") return 0;
   if(!securep(this_player())) return 1;
   else return 0;
}
