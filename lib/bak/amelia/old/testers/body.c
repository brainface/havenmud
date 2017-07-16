}

/************     /lib/body.c Data manipulation functions      *************/
void NewBody(string race) {
    if(!race)
      Limbs = ([ (Torso = "ooze") : ([ "parent" : 0, "children" : ({}),
      "health" : 50, "class" : 1, "armours" : 0 ]) ]);
    else Limbs = ([]);
    MissingLimbs = ([]);
    Fingers = ([]);
}

/* int CanWear(object armour, string *limbs)
 * object armour - the piece of armour being checked
 * string *limbs - the limbs on which the armour wants to be worn
 *    a nested array indicates that just one of the included limbs
 *    must be satisfied
 *
 * description
 * checks to see if a particular armour can be worn
 *
 * returns 1 if the armour can be worn on those limbs
 * returns 0 if the armour cannot be worn there for any reason
 *
 */
mixed CanWear(object ob, string *limbs) {
    string limb, verb_pr, verb_pt, short;
    int *types;
    int type, bad_types, i, maxi;

    if( !ob ) return 0;
    short = (string)ob->GetShort();
    if( !(type = (int)ob->GetArmourType()) )
      return capitalize(short) + " cannot be worn!";
    if( type & A_WEAPON ) {
        verb_pr = "wield";
        verb_pt = "wielded";
    }
    else {
        verb_pr = "wear";
        verb_pt = "worn";
    }
    if( !limbs || !(maxi = sizeof(limbs)) )
      return "Where should " + short + " be "+ verb_pt + "?";
    if( (string *)ob->GetWorn() )
      return "It is already being " + verb_pt + ".";

    // Verify that the the item can be worn on each limb specified by limbs.
    i = 0;
    foreach(limb in limbs) {
    
        // Nested arrays indicate that only one of the elements in the nested
        // array must be satisfied. Check for one valid limb, and replace the
        // nested array with the valid limb, if found.
        if( arrayp(limb) ) {
          string limb2;
          string validLimb = 0;
          int leastRings = -1;

          if(!sizeof(limb)) error("Bad limb specification to CanWear().\n");
          // Iterate through the nested array.
          foreach(limb2 in limb) {
            string* wornItems;

            // The limb will be valid if:
            // o The body has the named limb capable of wearing the armour type.
            // o There are no armours of the same type on that limb, except
            //   for rings, which can have up to GetFingers() of that type worn.
            if(!Limbs[limb2] || !(Limbs[limb2]["armours"] & type)) continue;
            wornItems = WornItems[limb2];
            
            // If the item is a ring, attempt to distribute the rings evenly
            // across the available hands.
            if(type == A_RING) {
              int currentRings;

              if(!sizeof(wornItems)) currentRings = 0;
              else currentRings = sizeof(filter(wornItems,
                (:(int)$1->GetArmourType() == A_RING:)));
              if(currentRings >= leastRings && leastRings != -1) continue;
              leastRings = currentRings;
              if(currentRings >= GetFingers(limb2)) continue;
            }
            else if(wornItems) {
              object wornItem;
              int tmpType = 0;

              foreach(wornItem in wornItems)
                if(wornItem) tmpType |= (int)wornItem->GetArmourType();
              if(tmpType & type) continue;
            }
            validLimb = limb2;
          }
          if(validLimb) limbs[i] = validLimb;
          else return "You cannot " + verb_pr + " that.";
        }
        else {
          if( !Limbs[limb] ) return "You have no " + limb + ".";
          if( !(Limbs[limb]["armours"] & type) ) {
              if( type & A_WEAPON )
                return "You cannot wield with " + limb + ".";
              else return "You cannot wear " + short + " on your " + limb + ".";
          }
        }
        i++;
    }
    switch(type) {
        case A_RING:
            if(maxi != 1)
              return "You can only wear " + short + " on one limb.";
            if( !WornItems[limbs[0]] ) return 1; /* nothing there, ring ok */
            /* count # worn rings */
            i = sizeof(filter(WornItems[limbs[0]],
              (: (int)$1->GetArmourType() == A_RING :)));
            if(i >= GetFingers(limbs[0]))
              return "You are already wearing too many rings there.";
            else return 1; /* ok */
        case A_GLOVE:
            if(maxi != 1)
              return "You can only wear " + short + " on one limb.";
            if( GetFingers(limbs[0]) > (int)ob->GetFingers() )
              return capitalize(short) + " does not seem to fit well on "
                "your " + limbs[0] + ".";
            bad_types = A_GLOVE | A_LONG_GLOVE | A_SOCK | A_LONG_SOCK |
              A_BOOT | A_LONG_BOOT;
            break;
        case A_LONG_GLOVE:
            if(maxi != 2)
              return capitalize(short) + " should be worn on two limbs.";
            if( limbs[0] == Limbs[limbs[1]]["parent"] ) { /* which is hand? */
                /* more fingers than this armour can stand */
                if(GetFingers(limbs[1]) > (int)ob->GetFingers())
                  return capitalize(short) + " does not seem to fit well on "
                    "your " + limbs[1] + ".";
            }
            else if(limbs[1] == Limbs[limbs[0]]["parent"]) {
                /* ok, first limb is hand, check it */
                if(GetFingers(limbs[0]) > (int)ob->GetFingers())
                  return capitalize(short) + " does not seem to fit well on "
                    "your " + limbs[1] + ".";
            }
            else return "Your " + limbs[0] + " is not connected to your " +
              limbs[1] + ".";
            bad_types = A_GLOVE | A_LONG_GLOVE | A_SOCK | A_LONG_SOCK |
              A_BOOT | A_LONG_BOOT;
            break;
        case A_BOOT: case A_SOCK:
            if(maxi != 1)
              capitalize(short) + " may only be worn on one limb.";
            if(type == A_SOCK) bad_types = A_SOCK | A_LONG_SOCK;
            else bad_types = A_BOOT | A_LONG_BOOT;
            break;
        case A_LONG_BOOT: case A_LONG_SOCK:
            if(maxi != 2)
              return capitalize(short) + " must be worn only on two limbs.";
            if(limbs[0] != Limbs[limbs[1]]["parent"] &&
              limbs[1] != Limbs[limbs[0]]["parent"])
              return "Your " + limbs[0] + " is not connected to your " +
                limbs[1] + ".";
            if(type == A_LONG_SOCK) bad_types = A_LONG_SOCK | A_SOCK;
            else bad_types = A_BOOT | A_LONG_BOOT;
            break;
        case A_HELMET: case A_VEST: case A_AMULET: case A_VISOR: case A_BELT:
            if(maxi != 1)
              return capitalize(short) + " may only be worn on one limb.";
            bad_types = type;
            break;
        case A_PANTS: case A_SHIRT:
            bad_types = type | A_CLOAK;
            break;
        case A_CLOAK:
            bad_types = A_CLOAK | A_SHIRT | A_PANTS;
            break;
        case A_SHIELD:
         if ( maxi != 1)
    return "You can only where " + short + " on one limb.";
            foreach(limb in limbs) {
                object worn_item;
                int tmp = 0;

                if( !WornItems[limb] ) continue; /* no armours, no prob */
                if( !Limbs[limb]["parent"] ) continue; /* torso ok for 2 */
                foreach(worn_item in WornItems[limb])  {
                    if( !worn_item ) continue;
                    tmp |= (int)worn_item->GetArmourType();
                }
                /* not gonna allow 2 shields or a shield and weapon here */
                if( tmp & (A_SHIELD | A_WEAPON) )
                  return "You cannot wear " + short + " there right now.";
            }
            return 1; /* ok */
        case A_WEAPON:
            foreach(limb in limbs) {
                object worn_item;
                int tmp = 0;

                if( !WornItems[limb] ) continue; /* nothing there, ok */
                foreach(worn_item in WornItems[limb]) {
                    if( !worn_item ) continue;
                    tmp += (int)worn_item->GetArmourType();
                }
                /* again, not allowing 2 weapons or a shield and weapon */
                if(tmp & (A_SHIELD | A_WEAPON))
                  return "You cannot wield " + short + " there right now.";
            }
            return 1; /* ok */
        case A_ARMOUR: case A_BODY_ARMOUR:
            bad_types = A_ARMOUR | A_BODY_ARMOUR;
            break;
        default: return 0; /* not any illegal stuff */
    }
    foreach(limb in limbs) {
        object worn_item;
        int tmp = 0;
        if( !WornItems[limb] ) continue; /* no preventing types */
        foreach( worn_item in WornItems[limb] ) {
            if( !worn_item ) continue;
            tmp |= (int)worn_item->GetArmourType();
        }
        if(tmp & bad_types)
          return "You cannot " + verb_pr + " " + short + " there right now.";
    }
    return 1; /* ok */
}

/* int AddLimb(string limb, string parent, int classes, int *armours)
 * string limb - the limb being added (required)
 * string parent - the limb to which this one is being attached (required)
 * int classes - rating of the limb's strength (optional)
 * int *armours - the types of armours which can be worn here (optional)
 *
 * defaults
 * classes defaults to 1
 * armours defaults to ({})
 *
 * description
 * adds the named limb to the body, attached at the named point
 * the limb classes starts at 1 for a torso (strongest)
 * to whatever the documentation rates as the weakest
 *
 * returns 1 on success, 0 on failure
 */
varargs int AddLimb(string limb, string parent, int classes, int *armours) {
    int arm = 0;

    if(!limb || Limbs[limb] || (parent && !Limbs[parent])) return 0;
    if(armours) {
        int i;

        i = sizeof(armours);
        while(i--) arm |= armours[i];
    }
    if(MissingLimbs[limb]) map_delete(MissingLimbs, limb);
    if( parent ) Limbs[parent]["children"] += ({ limb });
    else Torso = limb;
    if( !classes ) classes = 5;
    Limbs[limb] = ([ "parent" : parent, "children" : ({}), "class" : classes,
      "armours" : arm ]);
    Limbs[limb]["health"] = GetMaxHealthPoints(limb);
    return 1;
}

int RestoreLimb(string limb) {
    if( !MissingLimbs[limb] ) return 0;
    Limbs[limb] = MissingLimbs[limb];
    Limbs[Limbs[limb]["parent"]]["children"] += ({ limb });
    Limbs[limb]["health"] = GetMaxHealthPoints(limb);
    map_delete(MissingLimbs, limb);
    return 1;
}

/* int DestLimb(string limb)
 * string limb - the limb being removed
 *
 * description
 * removes a limb from the limbs mapping.  The limb isn't marked as mising,
 * and the monster doesn't die even if you remove a fatal limb.  Useful for
 * removing limbs from standard race types.  Removing the torso isn't allowed.
 *
 * returns -1 on error, 0 on failure, 1 on success
 */
int DestLimb(string limb) {
    string *kiddies;
    int i;

    if(!limb || !Limbs[limb]) return -1;
    if(!Limbs[limb]["parent"]) {
        return -1;
    }
    Limbs[Limbs[limb]["parent"]]["children"] -= ({ limb });
    if( (i = sizeof(kiddies = Limbs[limb]["children"])) )
      while(i--) DestLimb(kiddies[i]);
    map_delete(Limbs, limb);
    return 1;
}

/* int RemoveLimb(string limb, object agent)
 * string limb - the limb being removed
 * object agent - the agent who is responsible for the limb removal
 *
 * description
 * removes a limb from the limbs mapping and stores vital data in the
 * missing limbs mapping
 *
 * returns -1 on error, 0 on failure, 1 on success
 */
int RemoveLimb(string limb, object agent) {
    string *kiddies;
    int i;

    if(!limb || !Limbs[limb]) return -1;
    if(!Limbs[limb]["parent"] || Limbs[limb]["class"] == 1) {
        HealthPoints = 0;
        if( !Dying ) {
            Dying = 1;
            call_out((: eventDie, agent :), 0);
        }
        return 0;
    }
    Limbs[Limbs[limb]["parent"]]["children"] -= ({ limb });
    if( (i = sizeof(kiddies = Limbs[limb]["children"])) )
      while(i--) RemoveLimb(kiddies[i], agent);
    MissingLimbs[limb] = Limbs[limb];
    map_delete(Limbs, limb);
    if( environment() ) {
        object ob;

  message("environment",
    possessive_noun(GetName()) + "%^BOLD%^RED%^ " + limb + 
          "%^RESET%^ is severed!",
    environment(), ({ this_object() }) );
  message("environment",
    "Your %^BOLD%^RED%^" + limb + "%^RESET%^ is severed!",
     this_object() );
        ob = new(LIB_LIMB);
        ob->SetLimb(limb, GetCapName(), GetRace());
        ob->eventMove(environment());
        i = sizeof(WornItems[limb]);
        while(i--) {
            WornItems[limb][i]->SetWorn(0);
            WornItems[limb][i]->eventMove(ob);
        }
        while( i = sizeof(WornItems[limb]) )
          eventRemoveItem(WornItems[limb][i]);
    }
    return 1;
}

mapping GetLimb(string limb) {
    if(!limb || !Limbs[limb]) return 0;
    else return copy(Limbs[limb]);
}

/* string GetRandomLimb(string targ)
 * string targ - the targetted limb
 *
 * description
 * returns a random limb weighted towards the targetted limb
 */

string GetRandomLimb(string targ) {
    string array limbs;

    if( !targ ) {
	targ = GetTorso();
    }
    if( member_array(targ, (limbs=keys(Limbs))) == -1) {
	targ= GetTorso(); /* no target or illegal target, weight torso */
    }
    targ = (limbs + (targ ? ({ targ, targ }) : ({})))[random(sizeof(limbs)+2)];
    return targ;
}

string GetTorso() {
    string *limbs;
    int i;

    i = sizeof(limbs = keys(Limbs));
    while(i--) {
	if(!Limbs[limbs[i]]["parent"]) {
	    return limbs[i];
	}
    }
    return 0;
}

string array GetLimbs() {
    return (Limbs ? keys(Limbs) : 0);
}

int GetLimbClass(string limb) { return Limbs[limb]["class"]; }

string GetLimbParent(string limb) { return Limbs[limb]["parent"]; }

string array GetLimbChildren(string limb) {
    return Limbs[limb]["children"] + ({});
}

mapping GetMissingLimb(string limb) {
    return (limb ? copy(MissingLimbs[limb]) : 0);
}

string array GetMissingLimbs() { return keys(MissingLimbs); }

string GetLong(string nom) {
    string *limbs;
    string str;
    float h;
    
    str = (nom = capitalize(nom));
    h = percent(GetHealthPoints(), GetMaxHealthPoints());
    if( h < 10.0 ) str += " is mortally wounded.\n";
    else if( h < 20.0 ) str += " is near death.\n";
    else if( h < 30.0 ) str += " is severely injured.\n";
    else if( h < 40.0 ) str += " is badly injured.\n";
    else if( h < 50.0 ) str += " is hurt.\n";
    else if( h < 60.0 ) str += " is slightly injured.\n";
    else if( h < 70.0 ) str += " has some cuts and bruises.\n";
    else if( h < 80.0 ) str += " is in decent shape.\n";
    else if( h < 90.0 ) str += " is quite keen.\n";
    else str += " is in top condition.\n";
    limbs = GetMissingLimbs();
    if( sizeof(limbs) ) {
	int i, maxi;

	str += nom + " is missing " + add_article(limbs[0]); 
	for(i=1, maxi = sizeof(limbs); i<maxi; i++) {
	    if( i < maxi-1 ) str += ", " + add_article(limbs[i]);
	    else {
		if( maxi > 2 ) str += ",";
		str += " and " + add_article(limbs[i]);
	    }
	}
	str += ".\n";
    }
    return str;
}

string array GetWieldingLimbs() {
    return filter(keys(Limbs), (: (Limbs[$1]["armours"] & A_WEAPON) :));
}

/* int AddFingers(string limb, int x)
 * string limb - the limb to which fingers will be added
 * int x - the number of fingers being added, can be negative
 *
 * description
 * adds the given number of fingers to the given limb
 *
 * returns the total number of fingers after addition
 */

varargs int AddFingers(string limb, int x) {
    if((Fingers[limb] += x) < 1) Fingers[limb] = 1;
    return Fingers[limb];
}

int GetFingers(string limb) {
    return Fingers[limb];
}

varargs object *GetWorn(string limb) {
    if(!limb) {
        object *ret = ({});
        string *limbs;
        int i;

        i = sizeof(limbs = keys(Limbs));
        while(i--) if(WornItems[limbs[i]]) ret += ({ WornItems[limbs[i]] });
        return distinct_array(ret);
    }
    else if(!WornItems[limb]) return ({});
    else return (WornItems[limb] + ({}));
}

varargs mixed GetWielded(string limb) {
    if(!limb) {
        object *ret = ({});
        string *limbs;
        int i;

        i = sizeof(limbs = keys(Limbs));
        while(i--) {
            if(!WornItems[limbs[i]]) continue;
            else ret += filter(WornItems[limbs[i]],
              (: (int)$1->GetArmourType() == A_WEAPON :));
        }
        return distinct_array(ret);
    }
    else if(!WornItems[limb]) return 0;
    else {
        object *ret;

        ret = filter(WornItems[limb], (: (int)$1->GetArmourType() == A_WEAPON :));
        if(sizeof(ret)) return ret[0];
        else return 0;
    }
}

/* varargs static int AddHealthPoints(int x, string limb, object agent)
 * int x - number of points being added, may be negative (required)
 * string limb - the limb to which health is being added (optional)
 * object agent - the living responsible for this damage
 *
 * defaults
 * limb defaults to 0
 *
 * description
 * if the value of limb is not zero, then "x" number of health points will
 * be added to limb "limb"
 * if he value is 0, then the overall health points will be modified
 *
 * returns the remaining number of health points for the limb in question
 * or for the overall health points
 */

varargs static int AddHealthPoints(int x, string limb, object agent) {
    int y;

    if( limb ) {
        if( !Limbs[limb] ) return -1;
        if((Limbs[limb]["health"] += x) < 1) Limbs[limb]["health"] = 0;
        else if(Limbs[limb]["health"] > (y = GetMaxHealthPoints(limb)))
          Limbs[limb]["health"] = y;
        return Limbs[limb]["health"];
    }
    else {
        if((HealthPoints += x) < 1) HealthPoints = 0;
        else if(HealthPoints > (y = GetMaxHealthPoints())) HealthPoints = y;
        if( HealthPoints < 1 ) {
            if( !Dying ) {
                Dying = 1;
                call_out( (: eventDie, agent :), 0);
            }
        }
	else {
	    float h = percent(GetHealthPoints(), GetMaxHealthPoints());

	    if( h < COLLAPSE_AT ) {
		eventCollapse();
	    }
	}
        return HealthPoints;
    }
}

varargs int GetHealthPoints(string limb) {
    if(limb) {
        if(!Limbs[limb]) return -1;
        else return Limbs[limb]["health"];
    }
    else return HealthPoints;
}

varargs int GetMaxHealthPoints(string limb) { return 0; }

/* int AddMagicPoints(int x)
 * int x - the number of magic points being added, may be negative
 *
 * description
 * adds magic points to the body
 *
 * returns the remaining magic points
 */

int AddMagicPoints(int x) {
    int y;

    if((MagicPoints += x) < 1) MagicPoints = 0;
    else if(MagicPoints > (y = GetMaxMagicPoints())) MagicPoints = y;
    return MagicPoints;
}

int GetMagicPoints() { return MagicPoints; }

int GetMaxMagicPoints() { return 0; }

/* int AddStaminaPoints(int x)
 * int x - number of stamina points being added
 *
 * description
 * adds "x" stamina points, can be negative
 *
 * returns the remaining number of stamina points
 */

float AddStaminaPoints(mixed x) {
    float y;

    if( !intp(x) && !floatp(x) )
      error("Bad argument 1 to AddStaminaPoints().\n");
    if( intp(x) ) x = to_float(x);
    if((StaminaPoints += x) < 0.1) StaminaPoints = 0.0;
    else if(StaminaPoints > (y = GetMaxStaminaPoints())) StaminaPoints = y;
    return StaminaPoints;
}

int GetStaminaPoints() { return to_int(StaminaPoints); }

float GetMaxStaminaPoints() {  return 0; }

int AddMagicProtection(class MagicProtection cl) {
   if (sizeof(GetMagicProtection()) >= 2) {
     return 0;
    }
    if( ( !cl->absorb && !(cl->protect && cl->time) ) ||
        ( cl->hit && !functionp(cl->hit) ) ||
        ( cl->end && !functionp(cl->end) ) ||
        ( !cl->bits )
      ) {
        error("Illegal class setting passed to AddMagicProtection.\n");
        return 0;
      }
    cl->timestamp = time();
    Protection += ({ cl });
    return 1;
}

class MagicProtection array GetMagicProtection() { return Protection; }

int RemoveMagicProtection(int i) {
    if( i > sizeof(Protection) - 1 ) return 0;
    if( Protection[i]->end ) {
	if( !(functionp(Protection[i]->end) & FP_OWNER_DESTED) ) {
	    evaluate(Protection[i]->end, this_object());
	}
    }
    Protection -= ({ Protection[i] });
    return 1;
}

int GetDying() { return Dying; }

int SetSleeping(int x) { return (Sleeping = x); }

int GetSleeping() { return Sleeping; }

int SetBlind(int x) { return (Blind = x); }

int GetBlind() { return (Blind); }

int AddBlind(int x) { 
   if ((Blind + x) < 0 ) return (Blind = 0);
  return (Blind += x);
  }


int AddAlcohol(int x) {
  if ((Alcohol + x) < 0) return (Alcohol = 0);
  else return (Alcohol += x);
  }

int GetAlcohol() { return Alcohol; }

int AddCaffeine(int x) { return (Caffeine += x); }

int GetCaffeine() { return Caffeine; }

int AddDrink(int x) {
  if ((Drink + x) < 0) { return (Drink = 0); }
  else return (Drink += x);
  }

int GetDrink() { return Drink; }

int AddFood(int x) {
  if ((Food + x) < 0) return (Food = 0);
  else return (Food += x);
  }

int GetFood() { return Food; }

int AddPoison(int x) {
    Poison += x;
    if( Poison < 1 ) {
	Poison = 0;
    }
    return Poison;
}

int GetPoison() { return Poison; }

string GetResistance(int type) { return "none"; }

string GetRace() { return 0; }

string GetName() { return 0; }

string GetCapName() { return 0; }

int GetHeartRate() {
    int rate;

    rate = (GetAlcohol() - GetCaffeine());
    if( rate > 50 ) rate = 6;
    else if( rate > 25 ) rate = 5;
    else if( rate > 0 ) rate = 4;
    else if( rate > -25 ) rate = 3;
    else rate = 2;
    return rate;
}

int GetPosition() {
   return Position;
 }
int GetHealRate() {
    int heal = 1;

    heal += (GetDrink() + GetFood()) / 25;
    heal += (GetPosition()/4);
    heal *= (1 + (GetSleeping() > 1) + (GetAlcohol() > 50));
    return heal;
}


string GetHealthShort() {
    string cl, sh;
    float h;

    if( !(sh = GetShort()) ) return 0;
    h = percent(GetHealthPoints(), GetMaxHealthPoints());
    if( h > 90.0 ) cl = "%^BOLD%^GREEN%^";
    else if( h > 75.0 ) cl = "%^GREEN%^";
    else if( h > 50.0 ) cl = "%^BOLD%^BLUE%^";
    else if( h > 35.0 ) cl = "%^BLUE%^";
    else if( h > 20.0 ) cl = "%^BOLD%^RED%^";
    else cl = "%^RED%^";
    return cl + capitalize(sh);
}


int SetPosition(int x) {
    Position = x;
}

mixed SetProtect(function f) { return (Protect = f); }

function GetProtect() { return Protect; }


void eventCheckStatus() {
   int StamPer;

   if (GetUndead() ) return;
  switch ( (GetFood()/8) ) {
     case 0:
       eventReceiveDamage(0,HUNGER,random(8),1);
        eventPrint("You are starving.");
       break;
    case 1:
        eventPrint("You are fairly hungry.");
        break;
    case 2:
         eventPrint("You are slightly hungry.");
         break;
    default:
         break;
       }
  switch ( (GetDrink()/8) ) {
    case 0:
        eventPrint("You are nearly dehydrated!");
        eventReceiveDamage(0, HUNGER, random(3), 1);
        break;
    case 1:
        eventPrint("You are fairly dry-mouthed.");
        break;
    case 2:
        eventPrint("You are slightly thirsty.");
        break;
    default: 
        break;
     }
  StamPer = (GetStaminaPoints());
  switch (StamPer) {
     case 0..30:
       if (!(random(2))) {
          eventCollapse();
           }
        eventPrint("You are exhausted.");
        break;
     case 31..45:
        eventPrint("You are near exhaustion.");
        break;
     case 46..60:
        eventPrint("You are very tired.");
        break;
    case 61..75:
        eventPrint("You are slightly tired.");
        break;
      default:
         break;
      }
  if (GetPoison() > 0) {
     eventForce("shiver");
     eventPrint("You shiver with the poison running through you.");
     eventReceiveDamage(0, POISON, random(15), 1);
    }
  }
