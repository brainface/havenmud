/*    /lib/props/inventory.c
 *    From the Dead Souls V Object Library
 *    Inheritable for objects that manage inventories
 *    Created by Descartes of Borg 961222
 *    Version: @(#) inventory.c 1.2@(#)
 *    Last modified: 96/12/31
 */
object CheckLimit(string, object, int);
private static mapping Inventory = ([]);

void eventLoadInventory();
static void eventLoadItem(string file, mixed args, int count);

mapping GetInventory() {
    return Inventory;
}

mapping SetInventory(mapping mp) {
    foreach(string key, mixed val in mp) {
         if( key[<2..] == ".c" ) {
	     key = key[0..<3];
	 }
	 if( key[0] != '/' ) {
	     key = "/" + key;
	 }
         Inventory[key] = val;
    }
    eventLoadInventory();
    return Inventory;
}

void eventLoadInventory() {
    object array items = map(all_inventory(this_object()), (: base_name :));
    
    foreach(string file, mixed args in Inventory) {
	eventLoadItem(file, args, sizeof(filter(items, (: $1 == $(file) :))));
    }
}

mapping AddInventory(string key, mixed val) {
  Inventory[key] = val;
  eventLoadInventory();
  return Inventory;
  }

static void eventLoadItem(string file, mixed args, int count) {
  int limit;
  object ob;
  
  if( intp(args) ) { // Number of items to clone
	
/* This is used in Nightmare for unique stuff. */
	  if (args < 0) {
	    error("**Negative inventory #.  Use SetLimit");
	    return;
	    }
/* args is a positive int */
	args = args - count;
	
	while( args > 0 ) {
	  ob = new(file);
		limit = file->GetLimit();
		if (limit) { ob = CheckLimit(file, ob, limit); }
		if(ob) { ob->eventMove(this_object()); } 
		args--;
	  }
	}  
}

/* Checks for a limit on the the number of active copies of a
   specified object. */

object CheckLimit(string filename, object ob, int limit) {
  object *kiddies = children(filename);
  kiddies -= ({ ob });
  kiddies = filter(kiddies, (: $1 :) );
  kiddies = filter(kiddies, (: environment :));
  if (sizeof(kiddies) >= limit) ob->eventDestruct();
  return ob;
}

varargs void reset(int count) {
    eventLoadInventory();
}
