#include <lib.h>

inherit LIB_ITEM;

int CraftLevel;
string* CraftMaterials;
string* CraftSources;
string CraftName = "craftything";

string* SetCraftSources(string* str) { return CraftSources = str; }
string* GetCraftSources() { return CraftSources; }
int SetLevel(int x) { return CraftLevel = x; }
int GetLevel() { return CraftLevel;}
string* SetCraftMaterials(string* str) { return CraftMaterials = str; }
string* GetCraftMaterials() { return CraftMaterials; }

string* CraftColors;
string* SetCraftColors(string* str) {return CraftColors = str;}
string* GetCraftColors() {  return CraftColors; }

string GetCraftName() {return CraftName;}
string SetCraftName(string str) {return CraftName = str;}

string* Colors = ({
  "black",
  "red",
  "green",
  "yellow",
  "blue",
  "purple",
  "cyan",
  "white",
  "brown",
  "indigo",
});

string* GetColors() {
  return Colors;
}

int GetLegalColor(string color) {
  if (member_array(color, Colors) != -1) {
    return 1;
  }
  return 0;
}

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
  if (!sizeof(CraftSources)) return;
  if (!sizeof(CraftColors)) return;
  foreach(string adj in CraftSources) {
    AddAdjective(adj);
  }
  foreach(string adj in CraftColors) {
    AddAdjective(adj);
  }
  AddAdjective(GetCraftAdj());
  SetCraftColors( CraftColors );
  SetMaterials( CraftMaterials );
  SetValue(CraftLevel * 5);
}

string array GetSave() {
  return ({ "CraftColors", "CraftSources", "CraftLevel", "CraftMaterials" });
}


static void create() {
  ::create();
  SetId("craftything");
  SetShort("craftything");
  SetKeyName("craftything");
  SetLong("This is a craftything. You should never see this. Please bug me.");

  SetDestroyOnSell(1);
  
  call_out( (: SetCraftResult :), 0);
  //SetCraftResult();
      
  //AddSave( ({ "CraftColors", "CraftSources", "CraftLevel", "CraftMaterials",}) );

}
