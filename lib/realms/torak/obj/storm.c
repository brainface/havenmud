#include <lib.h>
inherit LIB_ITEM;

string OldClimate = "";
int LifeSpan = 50;

static void create() {
  ::create();
  SetKeyName("storm");
  SetId( ({ "storm", "snow", "snow storm" }) );
  SetShort("a snow storm");
  SetLong("A blizzard of snow flurries from the sky.");
  SetPreventGet("Looking up into the storm, you catch "
    "a %^BOLD%^snowflake%^RESET%^ on your tongue.");
  set_heart_beat(1);
}

int SetLifeSpan(int x) {
  return LifeSpan = x;
}

int GetLifeSpan() { return LifeSpan; }

string GetOldClimate() {
  OldClimate = environment()->GetClimate();
  }

void heart_beat() {
  environment()->SetClimate("arctic");
  LifeSpan--;
  if(LifeSpan <= 0) {
    if (environment()) {
      environment()->eventPrint(
        "%^BOLD%^The flurries stop falling as the storm subsides.%^RESET%^"
        );
    }
    environment()->SetClimate(OldClimate);
    eventDestruct();
    return;
  }
}
