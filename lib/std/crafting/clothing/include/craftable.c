#include <lib.h>

inherit LIB_ITEM;

int CraftLevel;
string* CraftMaterials;
string* CraftSources;

string* SetCraftSources(string* str) { return CraftSources = str; }
string* GetCraftSources() { return CraftSources; }
int SetLevel(int x) { return CraftLevel = x; }
int GetLevel() { return CraftLevel;}
string* SetCraftMaterials(string* str) { return CraftMaterials = str; }
string* GetCraftMaterials() { return CraftMaterials; }

string GetCraftAdj() {
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
      adj = "unfathomable";
      break;
    }	
    return adj;
}

void SetCraftResult() {
  string adj = GetCraftAdj();

  SetAdjectives( CraftSources + ({ adj }) );
  SetMaterials( CraftMaterials );
  SetValue(CraftLevel * 5);
}

static void create() {
  ::create();
  SetId("craftything");
  SetShort("craftything");
  SetKeyName("craftything");
  SetLong("This is a craftything. You should never see this. Please bug me.");

  SetDestroyOnSell(1);
  
  call_out( (: SetCraftResult :), 0);
      
  AddSave( ({ "CraftSources", "CraftLevel", "CraftMaterials",}) );
}
