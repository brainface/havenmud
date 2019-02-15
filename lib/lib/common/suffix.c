/* /lib/common/suffix.c
 * Mahkefel@haven.havenmud.com
 * March 2014
 *
 * Handles ad-hoc suffixes added to short descriptions
 */

// list of suffixes, as held by player object/ npc/ whatever.
// any object can have these.
mapping ShortSuffixes = ([ ]);

// add some suffix to the list of suffixes.
// something should later remove that suffix

// return a unique id for that suffix
string AddShortSuffix(string suffix) {
  string id = "";

  // there is a small chance of overlap here which i am IGNORING.
  id += time();
  id += random(1000);
  ShortSuffixes[id] = suffix;

  return id;
}

// remove a suffix from the list of suffixes
// generally called at the end of some timed function.
int RemoveShortSuffix(int Id) {
  if (ShortSuffixes[Id]) {
    map_delete(ShortSuffixes, Id);
    return 1;
  } else {
    return 0;
  }
}

// remove all shortsuffixes (happens on death, for instance.)
int ClearShortSuffixes() {
  ShortSuffixes = ([]);
  return 1;
}

// called by GetShort(),
// returns a list of suffixes as the player
// will see them.
string GetShortSuffixes() {
  string *uniqueSuffixes = ({ });
  string prettySuffixes = "";

  if (!ShortSuffixes) return "";

  // Always return "ridden" if has a rider
  if (this_object()->GetRider()) {
    prettySuffixes += " (ridden by " + this_object()->GetRider()->GetName() + ")";
  }
   
  if (this_object()->GetHitcher()) {
    prettySuffixes += " (hitched to " + this_object()->GetHitcher()->GetName() + ")";
  }

  /* doesn't want to work right and looks gross
  if (this_object()->GetSitters() && sizeof(this_object()->GetSitters())) {
    string *sitters = ({ });
    foreach(object sitter in this_object()->GetSitters()) {
      if (sitter != this_object()->GetRider()) {
        sitters += ({ sitter->GetName() });
      }
    }
    prettySuffixes += " (bearing " + item_list(sitters) + ")";   
    }*/

  // if someone is (on fire!) 5 times, only show it once
  foreach(string suffix in values(ShortSuffixes)) {
    if (member_array(suffix, uniqueSuffixes) == -1) {
      uniqueSuffixes += ({suffix});
    }
  }

  // turn the list of unique suffixes into a player readable string
  foreach(string suffix in uniqueSuffixes) {
    prettySuffixes += " ";
    prettySuffixes += suffix;
  }

  // and return!
  return prettySuffixes;
}

