/ no SetLightSensitivity is defined.... wont work this way without adding it 
#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <armour_types.h>
#include <vendor_types.h>

int AddShit();
int RemoveShit();
inherit LIB_ARMOUR;

static void create()
{
  armour::create();
  SetKeyName("helm");
  SetId(( { "helm" } ));
  SetShort("a white helm");
  SetLong("Blah Blah, test vision nonsense");
  SetMass(60);
  SetMaterial( ({ "mithril" }) );
  SetRepairDifficulty(15);
  SetWarmth(20);
  SetValue(100);
  SetDamagePoints(400);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
  SetArmourType(A_HELMET);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
  SetWear( (: AddShit :));
//  SetUnequip( (: RemoveShit() :));
}

int AddShit() {
	object who = this_player();		
	int array *oldvis = who->GetLightSensitivity();
	
//  if (who->GetTestChar()) debug("Old Vision: " + environment(this_object())->GetLightSensitivity());
  who->SetPermanentProperty("oldvis", ({oldvis}));
  this_object()->AddProperty("owner", who->GetName());
  who->SetLightSensitivity(({0, 100}));
//  if (who->GetTestChar()) debug("NewVision: " + who->GetLightSensitivity());
  return 1;
}

void heart_beat() {
	object who = this_object()->GetProperty("owner");	
	if (!GetWorn()) {
		who->SetLightSensitivity(who->GetProperty("oldvis"));
//    if (who->GetTestChar()) debug("Returned vision to: " + who->GetLightSensitivity());
  }
}

