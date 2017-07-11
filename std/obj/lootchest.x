// Mahkefel 2010     
// stealable storage chest takes inventory from 
//  owner
// I'd like to add coins to this, but it's a pain
//  guessing what currency owner should have.
#include <lib.h>                         

inherit LIB_STORAGE;                     

// This person "owns" the chest.
//   chest will be populated from their
//   store inventory.
object Owner;
int    SetOwner(object owner);
mixed  GetOwner();

static void create() {
  storage::create();       
  SetShort("a steel storage chest");
  SetKeyName("storage chest");      
  SetId( ({"chest" }) ); 
  SetAdjectives( ({ "steel","storage" }) );
  SetLong(
    "This heavy steel chest is locked and barred from "
    "casual pilferers. It must store something valuable "
    "to be so heavily guarded."                                 
  );                                                       
  SetMass(10);                                             
  SetCanClose(1);                                          
  SetClosed(1);
  SetMaxCarry(10000); // meh put a lot in there.
  SetPreventGet("The storage chest is securely affixed to the floor.");
  SetLockStrength(500); // GoodStrength?
  SetDamagePoints(25000);
  //SetPick(1);
  SetCanLock(1);
  SetLocked(1);
}

int SetOwner(object owner) {
  mapping inventory = ([]);
  int LockStrength;
  object storage;
  mapping goods = ([]);
  mapping loot = ([]);
  int count = 0;

  // Owner isn't vendor. Bail.
  if(!owner->GetStorageRoom()) return 0;

  Owner = owner;
  // Identify chest
  SetLong(
    "This heavy steel chest is locked and barred from "
    "casual pilferers. It must store something valuable "
    "to be so heavily guarded. An affixed note identifies the "
    "owner of the warded contents as " + Owner->GetName() + ".");
  LockStrength = 10 + Owner->GetLevel() * 15; // rough guestimate
  SetLockStrength(LockStrength);

  storage = owner->GetStorageRoom();

  goods = storage->GetInventory();
  
  foreach (string good in keys(goods)) {
    //debug("horribad spam: looking at " + good);
    if (!random(4)) {
      //debug("horribad spam: added loot: " + good);
      loot[good] = 1;
      count ++;
    } else {
      //debug("horribad spam: ignoring shop inventory");
    }
    if (count > 5) break;
  }
  if (sizeof(loot)) SetInventory(loot);
  return 1;
}

mixed GetOwner() {
  if (Owner) return Owner;
  return 0;
}
