/*  LIB_CONDITIONS
 *  A module to handle all forms of conditions which may
 *  be applied to a living thing.  Conditions should be defined
 *  included template
 *  10 June 2017  Duuk
 *  Condition - string name, int CONDITION_TYPE, int time
 */
#include <lib.h>
#include <conditions.h>

mapping Conditions;
mapping GetCondition(string str);
mapping AddCondition(string name, int condition_type, int condition_timer);
void *AddSave(string *m);
void eventPrint(string);

static void create() {
  Conditions = ([ ]);
  AddSave( ({ "Conditions" }) );
}

mapping GetCondition(string m) {
  if (!sizeof(keys(Conditions))) return 0;
  if (Conditions[m]) return Conditions[m];
  else return ([ ]);
}

string *GetConditions() {
  if (sizeof(Conditions))
    return keys(Conditions);
  else return ({ });
}

int GetConditionType(string cond) {
	if (!sizeof(GetConditions())) return 0;
	if (Conditions[cond]) return Conditions[cond]["type"];
  return 0;
}

int GetConditionTime(string cond) {                      
	if (!sizeof(GetConditions())) return 0;                
	if (Conditions[cond]) return Conditions[cond]["time"]; 
  return 0;                                              
}                                                      

/* When calling AddCondition() "
 * name" is what your condition is called - this is a "string"
 * condition_type is a bitwise of what the condition prevents
 * (see /include/conditions.h)
 * time = how many heart_beats should this condition last
 */

mapping AddCondition(string name, int condition_type, int condition_timer) {
  if (!Conditions) {
  	Conditions = ([ ]);
  }
  if (member_array(name, keys(Conditions)) == -1) {
  Conditions[name] = ([ "time" : condition_timer, "type" : condition_type ]);
  } else {
    if (Conditions[name]) {
      Conditions[name]["time"] += condition_timer;
      if (Conditions[name]["time"] <= 0) {
        eventPrint("You are no longer affected by " + name + ".");
        map_delete(Conditions, name);
        return 0;
      } 
      else return Conditions[name]["time"];
    }
  }
  return Conditions[name]["time"];
}

mapping RemoveCondition(string con) {
	if (!Conditions) return ([]);
	if (!sizeof(keys(Conditions))) return ([]);
	if (member_array(con, keys(Conditions)) == -1) return ([]);
	map_delete(Conditions, con);
	return Conditions;
}

void ResetConditions() {
	Conditions = ([]);
}

string GetConditionStatus(int c) {
	string *prev = ({ });
	 if (c & CONDITION_PREVENT_MOVE    )  prev += ({ "prevented from moving" });
   if (c & CONDITION_PREVENT_TALK    )  prev += ({ "prevented from talking" });
   if (c & CONDITION_PREVENT_HEAR    )  prev += ({ "prevented from hearing" });
   if (c & CONDITION_PREVENT_POSITION)  prev += ({ "prevented from changing position" });
   if (c & CONDITION_PREVENT_MAGIC   )  prev += ({ "prevented from using magic" });
   if (c & CONDITION_PREVENT_COMBAT  )  prev += ({ "prevented from attacking" });
   if (c & CONDITION_PREVENT_VISION  )  prev += ({ "prevented from seeing" });
   if (c & CONDITION_PREVENT_WIELD   ) prev += ({ "prevented from wielding" });
   if (c & CONDITION_SPECIAL         ) prev += ({ "special condition" });
   if (c & CONDITION_PREVENT_MAGIC_HEALING ) prev += ({ "prevented from using healing magic" });
   if (!sizeof(prev)) { return "no conditional effects"; }
   return conjunction(prev, "and");
}

int GetConditionFlag(int condition) {
	if (!Conditions) return 0;
	if (!sizeof(keys(Conditions))) return 0;
	foreach(string c in keys(Conditions)) {
		if (Conditions[c]["type"] & condition) return 1;
  }
  return 0;
}
	

void eventDisplayConditions(object who, object perspective) {
	string *con = ({ });
	string dis = "";
	
	con = GetConditions();
	if (who == perspective) {
		if (!sizeof(con)) {
			dis = "You are unaffected by any status conditions.";
		}
		foreach(string c in con) {
			dis += "You are affected by " + c + " (" + GetConditionStatus(GetConditionType(c)) + ") for " + GetConditionTime(c) + " more seconds. \n";
		}
	} else {
		if (!sizeof(con)) {
			dis = who->GetCapName() + " is unaffected by any status conditions.";
		}
		foreach(string c in con) {
			dis += who->GetCapName() + " is affected by " + c + " (" + GetConditionStatus(GetConditionType(c)) + ") for " + GetConditionTime(c) + " more seconds. \n";
		}
	}
	perspective->eventPrint(dis);
}

void *AddSave(string *m) { }

void heart_beat() {
	if (!Conditions) return;
	if (!sizeof(keys(Conditions))) return;
	foreach(string k in keys(Conditions)) {
		AddCondition(k, 0, -1);
	}
}
