#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

string* CraftSources;
int CraftLevel;
string* CraftMaterials;
string CraftPattern;

string* SetCraftSources(string* str) { return CraftSources = str; }
string* GetCraftSources() { return CraftSources; }
int SetLevel(int x) { return CraftLevel = x; }
int GetLevel() { return CraftLevel;}
string* SetCraftMaterials(string* str) { return CraftMaterials = str; }
string* GetCraftMaterials() { return CraftMaterials; }
string SetCraftPattern(string pattern) {return CraftPattern = pattern; }
string GetCraftPattern() {return CraftPattern;}

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
  // made from single type of fabric
  if (CraftSources[0] == CraftSources[1]) {
    SetShort("a "+adj+" "+CraftPattern +" bolt of "+ CraftSources[0] + " fabric");
    SetLong("A rolled up bolt of fabric made of " + CraftSources[0] + " yarn " +
  	 "arrayed in a " + CraftPattern + " pattern. It is clearly of " + adj + " quality.");
  } else {
    SetShort("a "+adj+" "+CraftPattern +" bolt of "+ CraftSources[0] + " and " + CraftSources[1] + " fabric");  	  
    SetLong("A rolled up bolt of fabric made of " + CraftSources[0] + " yarn and " + CraftSources[1] + " yarn " +
  	 "arrayed in a " + CraftPattern + " pattern. It is clearly of " + adj + " quality.");
  }

  SetValue(CraftLevel * 5);
  SetAdjectives( CraftSources + ({ adj }) );
  SetMaterial( CraftMaterials );
}

static void create() {
  ::create();
  SetKeyName("fabric");
  SetVendorType(VT_CLOTHING);
  SetMass(5);
  SetId( ({ "fabric", "bolt" }) );
  SetAdjectives( ({ }) );
  call_out( (: SetCraftResult :), 0);
  SetDestroyOnSell(1);
  AddSave( ({ "CraftSources", "CraftLevel", "CraftMaterials", "CraftPattern" }) );
}

mixed direct_sew_str_from_obj_with_obj() {
  return 1;
}
