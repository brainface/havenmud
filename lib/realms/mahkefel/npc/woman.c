#include <lib.h>
#include <daemons.h>
#include <damage_types.h>
inherit LIB_NPC;
inherit LIB_FEAR;

int wail = 0;
string* wailText = 
({"Tie him to a pole and break",
  "His fingers to splinters!",
  "Drag him to a hole until he",
  "Wakes up naked!",
  "Clawing at the ceiling",
  "Of his grave!",
  });
  
static void create() {
  npc::create();
  SetKeyName("woman in white");
  SetResistance(ALL_PHYSICAL, "immune");
  SetResistance(WATER, "immune");
  SetDie("The wraith fades away with one last wail of despair.");
  SetNoCorpse(1);
  SetRace("wraith");
  SetInvis(1);
  SetEncounter(100);
  SetUndead(1);
  SetResistLevel(50);
  SetFearLength(10);
  SetFearType("undead chill");
  SetClass("bard");
  SetLevel(random(40)+60);
  SetMorality(-500);
  SetShort("a wispy wailing woman in white");
  SetAdjectives( ({ "wispy", "wailing", "white" }) );
  SetId( ({ "woman in white", "woman" }) );
  SetLong("This mournful woman is a little hard to focus on. "
    "A long, flowing, transclucent white dress drapes over her "
    "thin frame. Blood stains mar her dress nad her eyesockets "
    "are shadowy and indescernable.");
  }

void init() {
  npc::init();
  fear::init();
 }

void heart_beat() {
  ::heart_beat();
  if (sizeof(GetMagicProtectionNames()) < 3) {
      eventForce("sing wail of the banshee");
  }
  
  if (!random(4)) {
    eventForce("say " + wailText[wail]);
    wail++;
    if (wail > 5) wail = 0;
  }
}



