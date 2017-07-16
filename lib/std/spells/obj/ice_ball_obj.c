#include <lib.h>
inherit LIB_ITEM;
#include <vendor_types.h>
 
void HalfMelt();
void AllMelt();
int half_melt = 150;
int all_melt = 250;

static void create() {
   item::create();
   SetKeyName("ice ball");
   SetId( ({ "ice ball","ball","ice" }) );
   SetAdjectives( ({ "ice" }) );
   SetShort("an ice ball");
   SetLong("It's a cold, spherical ball of ice that is slowly melting.");
   SetMass(5);
   SetValue(0);  // Changed by Duuk.  Ice balls don't have value!
   SetVendorType(VT_TREASURE);
   SetMaterial("natural");
   set_heart_beat(1);
}

void heart_beat() {
   half_melt--;
   all_melt--;
   if(!half_melt) { HalfMelt(); }
   if(!all_melt) { AllMelt(); }
}

void HalfMelt() {
   SetShort("a half-melted ice ball");
   SetAdjectives( ({ "half-melted","ice","mushy" }) );
   SetId( ({ "mushy ice ball","mushy ball","ball","ice ball","ice" }) );
   SetLong("It's a mostly cold, oblong ball of ice that is becoming "
           "mush gradually.");
   SetMass(3);
   SetValue(0);  // changed by Laoise. Ice balls don't have value.
  if(environment())
   message("my_message","The ice ball has now melted to about "
           "half its previous size.", environment());
}

void AllMelt() {
   if(environment())
   message("my_message","The ice ball has now completely melted "
           "down, it's only remaining trace is some quickly evaporating "
           "water.",environment());
   eventDestruct();
}
