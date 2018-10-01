#include <lib.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("manual");
  SetId( ({ "manual" }) );
  SetAdjectives( ({ "invasion", "bloody" }) );
  SetShort("a bloody invasion manual");
  SetLong("This manual was made from the flesh of some "
          "living creature, bound by strands of hair. It "
          "is completely drenched in blood. It is "
          "rectangular in shape but the corners are now "
          "blunt from age.\n"
          " Perhaps you could <read> it.");
  SetInvis(1);
  SetMass(1);
  SetRead( "default",
"\n"
" _________________________________________________________\n"
"|      HavenMUD Invader Simulator Manual  Version 1.0     |\n"
"|                                                         |\n"
"| Invader   Invadee   Level   Align  Notes    Summon      |\n"
" ---------------------------------------------------------\n"
"\n"  
"   Haven    Daemon    125     -1000  Fear   haven demon\n"
"   Haven    Pirate   50- 20   - 900  Army   haven pirates\n"
"   Haven    Undead   74- 20   - 500  A/F/S  haven undead\n"
"\n"   
"   Jidoor   Lzrdmen  15(R+15)   0    Army   jidoor lizardmen\n"
"   Jidoor   Orcs     30(R+ 5)   0    Army   jidoor orc\n"
"   Jidoor   Templar  95- 45     0    Army   jidoor templar\n"
"\n"
"   Lloryk   Lzrdmen  25- 15   - 200  Army   lloryk lizardmen\n"
"\n"   
"   Parva    Bandit     15     - 300  Detail parva bandit\n"
"   Parva    Pirate   45- 20   - 500  Army   parva pirate\n"
"   Parva    Templar  80- 45     0    Army   parva templar\n"
"   Parva    Undead   74- 20   - 500  A/F/S  parva undead\n"
"\n"
"   Sanctum  Bandit   20(R+12)   0    Detail sanctum bandit\n"
"\n"
"   Soleil   Daemon   65- 25   - 200  Army   soleil demon\n"
"   Soleil   Goblin   25(R+10)   0    Army   soleil goblin\n"
"   Soleil   Ogre     38- 25   - 300  Army   soleil ogre\n"
"\n"
"   Tairi    Ninja    70(R+25)   0    Army   tairi ninja\n"
    );
}