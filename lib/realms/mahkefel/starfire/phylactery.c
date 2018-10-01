/* Phylactery
 * Holds stats for undead (particularly liches)
 * Can be targetted like a corpse for the raise dead spell line
 * (probably reveal killer spelllines too. Bonus!)
 *
 * Mahkefel 2017, made for Mel for Starfire
 */

#include <lib.h>

inherit LIB_ITEM;

// corpse info
string Classy = 0;
string Race = 0;
string Gender = 0;
int Level = 0;
string Source = 0;

string SetClass(string classy) {  return Classy = classy; }
string GetClass() { return Classy; }
string SetRace( string race) { return Race = race; }
string GetRace() {return Race;}
string SetGender(string gender) { return Gender = gender; }
string GetGender() {return Gender;}
int SetLevel(int level) {return Level = level;}
int GetLevel() {return Level;}

// short of the dude that died
string SetSource(string source) {return Source = source;}
string GetSource() {return Source;}

SetupPhyl() {
  if (Source) {
    SetRead("default",Source);
    SetRead("label",Source);
    AddLong(" A simple parchment label is stuck to the top, somewhat "
      "marring the artistry.");
  }
}

static void create() {
  item::create();
  SetKeyName("phylactery");
  SetShort("a golden phylactery");
  SetId(({ "phylactery" }));
  SetAdjectives( ({ "golden" }) );
  SetLong(
    "An ornate golden skull covered with strange runes. The eyes are polished "
    "emerald, and silver teeth fill the mouth."
  );
  call_out( (:SetupPhyl:),0);
  AddSave( ({ "Classy", "Race", "Gender", "Level", "Source" }) );
}

