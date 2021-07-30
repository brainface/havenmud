#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

string* CraftSources;
int CraftLevel;
string* CraftMaterials;

string* SetCraftSources(string* str) { return CraftSources = str; }
string* GetCraftSources() { return CraftSources; }
int SetLevel(int x) { return CraftLevel = x; }
int GetLevel() { return CraftLevel;}
string* SetCraftMaterials(string* str) { return CraftMaterials = str; }
string* GetCraftMaterials() { return CraftMaterials; }

void SetCraftResult() {
  string adj;
  switch(CraftLevel) {
    case 0..4:
      adj = "novice";
      break;
    case 5..24:
      adj = "ordinary";
      break;
    case 25..49:
      adj = "extraordinary";
      break;
    case 50..99:
      adj = "phenomenal";
      break;
    case 100..249:
      adj = "exemplary";
      break;
    case 250..399:
      adj = "divine";
      break;
    case 400..500:
      adj = "mythological";
      break;
    default:
      adj = "torn";
      break;
    }
  SetShort("a spool of " + adj + " " + CraftSources[0] + " thread");
  SetLong("This tightly wound spool of " + CraftSources[0] +" is clearly of " + adj + " quality.");
  SetValue(CraftLevel * 5);
  SetAdjectives( CraftSources + ({ adj }) );
  SetMaterials( CraftMaterials );
}

static void create() {
  ::create();
  SetKeyName("thread");
  SetVendorType(VT_CLOTHING);
  SetMass(5);
  SetId( ({ "thread" }) );
  SetProperty("craft_thread",1);
  call_out( (: SetCraftResult :), 0);
  SetDestroyOnSell(1);
  AddSave( ({ "CraftSources", "CraftLevel", "CraftMaterials" }) );
}

direct_attach_obj_to_obj() {
  return 1; 
}

mixed indirect_sew_str_from_obj_with_obj() {
  return 1;
}
