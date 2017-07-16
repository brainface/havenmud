#include <lib.h>
#include <vendor_types.h>
#include <meal_types.h>
inherit LIB_MEAL;

string MeatSource, MeatAdjective;
int MeatClass;
int MeatLevel;

string SetMeatSource(string str) { return MeatSource = str; }
string GetMeatSource() { return MeatSource; }
int SetMeatClass(int x) { return MeatClass = x; }
int SetMeatLevel(int x) { return MeatLevel = x; }
string SetAdjective(string str) { return MeatAdjective = str; }

void SetMeat() {
  string adj;
  switch(MeatClass) {
    case 0..9:
      adj = "charred";
      break;
    case 10..19:
      adj = "burned";
      break;
    case 20..29:
      adj = "well done";
      break;
    case 30..39:
      adj = "nicely cooked";
      break;
    case 40..49:
      adj = "tasty";
      break;
    case 50..10000:
      adj = "delicious";
      break;
    default:
      adj = "tasteless";
      break;
    }
  SetShort(add_article(adj) + " slab of " + MeatSource + " meat");
  SetLong("This " + adj + " meat formerly belonged to " + add_article(MeatSource) + ".");
  SetValue(MeatClass * 3 * MeatLevel);
  SetAdjectives( ({ MeatSource, adj }) );
  SetAdjective(adj);
  AddSave( ({ "MeatSource", "MeatClass", "MeatLevel", "MeatAdjective" }) );
  SetMealMessages(
     "The " + MeatSource + " meat is " + MeatAdjective + " and filling.",
     "$N eats a slab of " + MeatSource + " meat."
  );
  SetStrength(MeatClass);
}

static void create() {
  ::create();
  SetKeyName("meat");
  SetVendorType(VT_FOOD);
  SetMealType(MEAL_FOOD);
  SetMass(20);
  SetId( ({ "meat" }) );
  SetAdjectives( ({ }) );
  call_out( (: SetMeat :), 0);
  SetDestroyOnSell(1);
}

