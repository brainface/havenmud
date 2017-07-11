#include <lib.h>
#include <loot.h>
#include <daemons.h>
#include <std.h>
#include <save.h>
inherit LIB_DAEMON;
mapping Loot;

void SaveLoot();
void LoadLoot();
void PreLoadLoot();
void LootReport();

static void create() {
  ::create();
  Loot = ([]);
  PreLoadLoot();
  LoadLoot();
  LootReport();
}

mapping GetOddsTable(int level) {
  mapping Odds = ([
   LOOT_COMMON    : 20,
   LOOT_UNCOMMON  : 0, 
   LOOT_RARE      : 0,
   LOOT_VERY_RARE : 0, 
    ]);
  if (level > 10)  Odds[LOOT_UNCOMMON] = 5; 
  if (level > 50)  Odds[LOOT_UNCOMMON] = 15;
  if (level > 100) Odds[LOOT_UNCOMMON] = 25;     
  if (level > 50)  Odds[LOOT_RARE]     = 5;
  if (level > 150) Odds[LOOT_RARE]     = 15;
  if (level > 250) Odds[LOOT_RARE]     = 25;    
  if (level > 100) Odds[LOOT_VERY_RARE]= 5;
  if (level > 250) Odds[LOOT_VERY_RARE]= 15;
  if (level > 500) Odds[LOOT_VERY_RARE]= 25;
  return Odds;
}  

object GenerateLoot(int loot_type, int loot_frequency) {
  string *loot_options = ({ });
}

void eventDie(object npc) {
  mixed *SpecialLoot = npc->GetSpecialLoot();
  mapping Odds = GetOddsTable(npc->GetLevel());
  return;
}

void PreLoadLoot() {
  int i = 0;
  while (i <= MAX_LOOT_INT) {
    Loot[1 << i] = ({ });
    i++;
  }
}

void SaveLoot() {
  unguarded( (: save_object, SAVE_LOOT :) );
}

void LoadLoot() {
  unguarded( (: restore_object, SAVE_LOOT :) );
}

void AddLoot(object what) {
  int i = 0;
  foreach(int ty in keys(Loot)) {
    Loot[ty] -= ({ base_name(what) });
  }
  if (what->GetLootType() == LOOT_NONE) return;
  while (i < MAX_LOOT_INT) {
    if (what->CheckLootType(1 << i)) Loot[1 << i] = distinct_array(Loot[1 << i] + ({ base_name(what) }));
    i++;
  }
  SaveLoot();
}

void LootReport() {
  string str;
  unguarded( (: rm, "/doc/help/immortals/loot" :) );
  str = implode(Loot[LOOT_NONE], ", ");
  unguarded( (: write_file, "/doc/help/immortals/loot", "LOOT_NONE\n" + str + "\n" :) );
  str = implode(Loot[LOOT_ANIMAL], ", ");
  unguarded( (: write_file, "/doc/help/immortals/loot", "LOOT_ANIMAL\n" + str + "\n" :) );
  str = implode(Loot[LOOT_SENTIENT], ", ");
  unguarded( (: write_file, "/doc/help/immortals/loot", "LOOT_SENTIENT\n" + str + "\n" :) );
  str = implode(Loot[LOOT_TOWN], ", ");
  unguarded( (: write_file, "/doc/help/immortals/loot", "LOOT_TOWN\n" + str + "\n" :) );
  str = implode(Loot[LOOT_WILDERNESS], ", ");
  unguarded( (: write_file, "/doc/help/immortals/loot", "LOOT_WILDERNESS\n" + str + "\n" :) );
  str = implode(Loot[LOOT_MAGICAL], ", ");
  unguarded( (: write_file, "/doc/help/immortals/loot", "LOOT_MAGICAL\n" + str + "\n" :) );
  str = implode(Loot[LOOT_FARMING], ", ");
  unguarded( (: write_file, "/doc/help/immortals/loot", "LOOT_FARMING\n" + str + "\n" :) );
  str = implode(Loot[LOOT_MINING], ", ");
  unguarded( (: write_file, "/doc/help/immortals/loot", "LOOT_MINING\n" + str + "\n" :) );
}