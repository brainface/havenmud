#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

string PeltSource;
int PeltClass;
int PeltLevel;

string SetPeltSource(string str) { return PeltSource = str; }
string GetPeltSource() { return PeltSource; }
int SetPeltClass(int x) { return PeltClass = x; }
int SetPeltLevel(int x) { return PeltLevel = x; }

void SetPelt() { 
  string adj;
  switch(PeltClass) {
    case 0..9:
      adj = "ruined";
      break;
    case 10..19:
      adj = "carefully handled";
      break;
    case 20..29:
      adj = "average quality";
      break;
    case 30..50:
      adj = "very good quality";
      break;
    case 51..99:
      adj = "fine";
      break;
    case 100..10000:
      adj = "flawless";
      break;
    default:
      adj = "tattered";
      break;
    }
  SetShort("a " + adj + " " + PeltSource + " skin");
  SetLong("This " + adj + " pelt formerly belonged to a " + PeltSource + ".");
  SetValue(PeltClass * 3 * PeltLevel);
  SetAdjectives( ({ PeltSource, adj }) );
}

static void create() {
  ::create();
  SetKeyName("skin");
  SetVendorType(VT_FUR);
  SetMass(20);
  SetId( ({ "skin", "pelt" }) );
  SetAdjectives( ({ }) );
  call_out( (: SetPelt :), 0);
  SetDestroyOnSell(1);
  AddSave( ({ "PeltSource", "PeltClass", "PeltLevel" }) );
}

