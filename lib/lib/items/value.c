/*    /lib/props/value.c
 *    From the Dead Souls V Object Library
 *    Basic value attributes
 *    Created by Descartes of Borg 970101
 *    Version: @(#) value.c 1.1@(#)
 *    Last modified: 97/01/01
 */

#include <vendor_types.h>
#include <loot.h>
#include <daemons.h>

private int DestroyOnSell    = 0;
private int Value            = 0;
private int VendorType       = VT_TREASURE;
private int RepairDifficulty = 0;
private mapping RepairSkills = ([]);
private string *Materials    = ({});
private int LootType         = LOOT_NONE;
private int LootFrequency    = LOOT_NEVER;

int GetDestroyOnSell() {
    return DestroyOnSell;
}

mixed direct_appraise_obj() { return 1; }

int SetDestroyOnSell(int x) {
    if( x ) {
	DestroyOnSell = 1;
    }
    else {
	DestroyOnSell = 0;
    }
    return DestroyOnSell;
}

string array GetSave() {
    return ({ "Value" });
}

int GetValue() {
    return Value;
}
 
int SetValue(int x) {
    if( !intp(x) ) {
	error("Bad argument 1 to SetValue().\n\tExpected: int, Got: " +
	      typeof(x) + "\n");
    }
    else {
	return (Value = x);
    }
}

int GetVendorType() {
    return VendorType;
}

int SetVendorType(int x) {
    if( !intp(x) ) {
	error("Bad argument 1 to SetVendorType().\n\tExpected: int, Got: " +
	      typeof(x) + "\n");
    }
    if( !(x & VT_ALL) ) {
	error("Invalid vendor type.\n");
    }
    return (VendorType = x);
}

int CanSell() {
    return 1;
}

string *SetMaterials(string *str) {
    if (arrayp(str)) Materials = str;
    else Materials = ({ str });
    return Materials;
}

string *SetMaterial(mixed str) {
    if (arrayp(str)) Materials = str;
    else Materials = ({ str });
    return Materials;
}

mapping SetRepairSkills(mapping mp) { return RepairSkills = mp; }

int SetRepairDifficulty(int x) { return RepairDifficulty = x; }

string *GetMaterials() { 
  string *sk = ({ });
    if (!sizeof(Materials)) {
    if (!sizeof(sk = keys(RepairSkills))) {
      return ({ });
    }
    foreach(string skill in sk) {
      sk -= ({ skill });
      skill = explode(skill, " ")[0];      
      sk += ({ skill });
    }
    sk -= ({ "weapon", "armour" });
    Materials = sk;
  }
  foreach(string mat in Materials) {
    if (!CLASSES_D->GetValidSkill(mat + " working")) {
      error("Bad Material: " + mat + " in " + base_name(this_object()));
      Materials -= ({ mat });
    }
  }
  return Materials;
}

int GetRepairDifficulty() { return RepairDifficulty; }

string *GetRepairSkills() { 
  string *sk = ({ });
    
  foreach(string material in GetMaterials()) {
    sk += ({ material + " working" });
  }
  if (VendorType & VT_ARMOUR) sk += ({ "armour smithing" });
  if (VendorType & VT_WEAPON) sk += ({ "weapon smithing" });
  return sk; 
}

int SetLootType(int x) { LootType = x; LOOT_D->AddLoot(this_object()); return LootType; }
int GetLootType()      { return LootType;     }

int CheckLootType(int x) { return LootType & x; }

int SetLootFrequency(int x) { return LootFrequency = x; }
int GetLootFrequency()      { return LootFrequency;     }

int direct_scrap_obj() {
/* Mahkefel 2017
 * allows item to be destroyed for scrap items.
 */
  return 1;
}
