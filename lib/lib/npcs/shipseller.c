#include <lib.h>
#include <daemons.h>
#include <vehicle.h>
inherit LIB_SENTIENT;

string LocalCurrency   = "imperials";
int LargestShip        = VS_DREADNAUGHT;
int LargestWeapon      = VW_DEVASTATING;
int LargestShield      = 0;
int LargestDrive       = VM_DEEP;
int LargestSensor      = VSE_WIDE;
float ShipModifier     = 1.0;
float WeaponModifier   = 1.0;
float ShieldModifier   = 1.0;
float SensorModifier   = 1.0;
float DriveModifier    = 1.0;
float RepairModifier   = 1.0;
float SalvageModifier  = 1.0;
string Wharf           = 0;

string SetWharf(string w) { return Wharf = w; }
string GetWharf() { return Wharf; }

float SetSalvageModifier(float f) { return SalvageModifier = f; }
float GetSalvageModifier() { return SalvageModifier; }

float SetShipModifier(float f) { return ShipModifier = f; }
float GetShipModifier() { return ShipModifier; }

float SetDriveModifier(float f) { return DriveModifier = f; }
float GetDriveModifier() { return DriveModifier; }

float SetSensorModifier(float f) { return SensorModifier = f; }
float GetSensorModifier() { return SensorModifier; }

float SetWeaponModifier(float f) { return WeaponModifier = f; }
float GetWeaponModifier() { return WeaponModifier; }

float SetShieldModifier(float f) { return ShieldModifier = f; }
float GetShieldModifier() { return ShieldModifier; }

float SetRepairModifier(float f) { return RepairModifier = f; }
float GetRepairModifier() { return RepairModifier; }

int SetLargestShip(int s) { return LargestShip = s; }
int GetLargestShip() { return LargestShip; }

int SetLargestShield(int s) { return LargestShield = s; }
int GetLargestShield() { return LargestShield; }

int SetLargestWeapon(int s) { return LargestWeapon = s; }
int GetLargestWeapon() { return LargestWeapon; }

int SetLargestSensor(int s) { return LargestSensor = s; }
int GetLargestSensor() { return LargestSensor; }

int SetLargestDrive(int s) { return LargestDrive = s; }
int GetLargestDrive() { return LargestDrive; }

string SetLocalCurrency(string c) { return LocalCurrency = c; }
string GetLocalCurrency() { return LocalCurrency; }

int eventNewShip(object who, string thing, string args) {
	mixed cost;
	float size;
	object ship, wharf;
	switch(thing) {
		case "yacht":
		  size = VS_YACHT;
		  break;
		case "galley":
		  size = VS_GALLEY;
		  break;
		case "cruiser":
		  size = VS_CRUISER;
		  break;
		case "dreadnaught":
		  size = VS_DREADNAUGHT;
		  break;
		default:
		  eventForce("speak Did you mean to buy a yacht, galley, "
		             "cruiser, or dreadnaught?");
		  return 1;
		  break;
		}
  if (!wharf = load_object(Wharf)) {
    debug("**Fucked up WharfRoom in " + base_name(this_object()) + "!");
    eventForce("say Um.  Don't mind me.  Waiting for Divine Intervention.");
    return 1;
    }
  if (size > LargestShip) {
  	eventForce("speak I'm sorry, I don't sell anything that big.");
  	return 1;
  	}
  cost = 10000;
  if (size == VS_YACHT)       cost *= 0.1;
  if (size == VS_CRUISER)     cost *= 4;
  if (size == VS_DREADNAUGHT) cost *= 10;
  cost = cost * currency_rate(LocalCurrency) * ShipModifier;
	cost = to_int(cost);
	if (who->GetCurrency(LocalCurrency) < cost) {
  	eventForce("speak It doesn't seem you have enough money for that.");
  	eventForce("speak I would charge you " + cost + " " + LocalCurrency + 
  	           " for that vessel.");
  	return 1;
  }
  who->AddCurrency(LocalCurrency, -cost);
  ship = new(LIB_SHIP);
  ship->SetVehicleSize(size);
  ship->SetDamagePoints(to_int(size * 200000));
  ship->SetVehicleName(args);
  ship->SetOwner(who->GetKeyName());
  ship->SetId( ({ thing, args, "ship" }) );
  ship->SetLong("This is the " + thing + " " + args + ".");
  ship->SetShort("the " + thing + " " + args);
  ship->SetVId(ship->GetId());
  ship->SetVLong("This is the " + thing + " " + args + ".");
  ship->SetVShort("the " + thing + " " + args);
  ship->eventMoveLiving(Wharf);
  CHAT_D->eventSendChannel("SHIP SALE", "reports", 
    capitalize(who->GetKeyName()) + " bought the " + thing + 
               " " + args);
  VEHICLES_D->AddShip(ship);
  eventForce("speak The " + thing + " " + args + " is now " 
             "waiting for you at " + Wharf->GetShort());
  send_messages("charge", "$agent_name $agent_verb $target_name " +
                cost + " "  + LocalCurrency + " for the ship.",
                this_object(), who, environment(who) );
	return 1;
}

int GetAppraisal(object ship) {
  int cost;
  cost = ship->GetDamagePoints();
  cost = cost * currency_rate(LocalCurrency) * 0.02 * ShipModifier;
  return cost;
}

int eventAppraiseShip(object who, string what) {
  object ship = 0;
  object wharf;
  int cost, mod;
  float comparison;
  ship = present(what, wharf = load_object(Wharf));
  if (!ship) {
    eventForce("speak Trying to cheat me, eh? That's not nice. I don't see any ship called "
               + what + " docked at my wharf!");
    return;
  }
  cost = GetAppraisal(ship);
  if (who->GetStaminaPoints() < 5) {
    eventForce("speak You look a bit too tired to haggle with me right now.");
    return 1;
  }
  if (ship->GetKeyname() == "dinghy") {
    eventForce("speak No thanks, I have enough firewood to get me by.");
    return 1;
  }
  if (ship->GetOwner() != who->GetKeyName()) {
    eventForce("speak Since it's pirated, I think I'll take a little off the top.");
    cost = cost * 0.333;
  }
    mod = GetSkillLevel("bargaining");
    if (!mod) mod = 1;
    comparison = who->GetSkillLevel("bargaining") / mod;
    if (who->GetCharisma() >  35) comparison += 0.05;
    if (who->GetCharisma() >  50) comparison += 0.05;
    if (who->GetCharisma() >  75) comparison += 0.05;
    if (who->GetCharisma() > 100) comparison += 0.05;
    if (who->GetCharisma() > 115) comparison += 0.05;
    if (comparison > 1.0) comparison = 1.0;
    if (comparison < 0.333) comparison = 0.333;
    if (who->GetTestChar())  debug("Comp: " + comparison);
    cost = to_int(cost * comparison);
    who->eventTrainSkill("bargaining", mod, GetSkillLevel("bargaining"), 1);
    who->AddStaminaPoints(-5);
  eventForce("speak I will give you " + cost + " " + GetLocalCurrency() + " for that ship.");
  return 1;
}

int eventBuyShip(object who, string what) {
  object ship = 0;
  object wharf;
  int cost, mod;
  float comparison;
  ship = present(what, wharf = load_object(Wharf));
  if (!ship) {
    eventForce("speak Trying to cheat me, eh? That's not nice. I don't see any ship called "
               + what + " docked at my wharf!");
    return;
  }
  if (!ship->CanSell(who)) {
    eventForce("speak I can't buy that ship from YOU.");
    return 1;
  }
  cost = GetAppraisal(ship);
  if (ship->GetOwner() != who->GetKeyName()) {
    eventForce("speak Since it's pirated, I think I'll take a little off the top.");
    cost = 0.333;
  }
    mod = GetSkillLevel("bargaining");
    if (!mod) mod = 1;
    comparison = who->GetSkillLevel("bargaining") / mod;
    if (who->GetCharisma() >  35) comparison += 0.05;
    if (who->GetCharisma() >  50) comparison += 0.05;
    if (who->GetCharisma() >  75) comparison += 0.05;
    if (who->GetCharisma() > 100) comparison += 0.05;
    if (who->GetCharisma() > 115) comparison += 0.05;
    if (comparison > 1.0) comparison = 1.0;
    if (comparison < 0.333) comparison = 0.333;
    if (who->GetTestChar())  debug("Comp: " + comparison);
    cost = to_int(cost * comparison);
    who->eventTrainSkill("bargaining", mod, GetSkillLevel("bargaining"), 1);

  
  send_messages( ({ "buy" }),
    "$agent_name $agent_verb " + what + " from $target_name for " + cost + " " + GetLocalCurrency() + ".",
    this_object(), who, environment(who) );
  who->AddCurrency(GetLocalCurrency(), cost);
  ship->DeleteVehicle();
  ship->eventDestruct();
  return 1;
}

int eventSalvage(object who, string arg) {
	object ship = 0;
	object *allships = children(LIB_SHIP);
	int cost, size;
	
	foreach(object ss in allships) {
		if (ss->GetVehicleName() == arg) ship = ss;
	}
        if (!ship) {
                eventForce("speak Arr, but I can't find any ship named " + arg +
                           ", mayhaps you're foolin with me?");
                return 1;
        }
	if (ship->GetKeyname() == "dinghy") {
		eventForce("speak Best just to let that be.");
		return 1;
	}

	if (ship) {
		size = ship->GetVehicleSize();
		cost = size * currency_rate(LocalCurrency) * 4000 * SalvageModifier;
		
	}
	if (who->GetCurrency(GetLocalCurrency()) < cost) {
		eventForce("speak That would require you pay me " + cost + 
		           " " + GetLocalCurrency());
		return 1;
	}
	if (ship->GetOwner() != who->GetKeyName()) {
		eventForce("speak You can't salvage a ship you don't own, Mate.");
		return 1;
	}
	who->AddCurrency(GetLocalCurrency(), -cost);
	send_messages("charge", "$agent_name $agent_verb $target_name " +
	              cost + " " + GetLocalCurrency() + " to salvage $target_possessive ship.",
	              this_object(), who, environment() );
	ship->eventMoveLiving(Wharf, "A salvage ship arrives and tows $N away.", 
	                             "A salvage ship tows $N into the harbour.");
	return 1;
}	

int eventSellShields(object who, string arg, string rest) {
	mixed cost;
	int size;
	object ship, wharf;
	switch (arg) {
		case "small" :
		  size = VSH_SMALL;
		  break;
		case "medium":
		  size = VSH_MEDIUM;
		  break;
		case "large":
		  size = VSH_LARGE;
		  break;
		default:
		  eventForce("speak Did you want small, medium, or large shields?");
		  return 1;
		  break;
		}
	if (size > LargestShield) {
		eventForce("speak I don't sell anything that big.");
		return 1;
	}	
	ship = present(rest, wharf = load_object(Wharf));
  if (!ship) {
  	eventForce("speak Sorry, but I don't see " + rest + " docked at " +
  	           wharf->GetShort());
  	return 1;
  }
  if (ship->GetKeyname() == "dinghy") {
    eventForce("speak Any additional weight's going to sink her like a stone.");
    return 1;
  }
  if (size > ship->GetVehicleSize()) {
  	eventForce("speak That ship isn't big enough to handle " + arg +
  	           " shields.  Sorry.");
  	return 1;
  }
  cost = size * 5000 * currency_rate(LocalCurrency) * ShieldModifier;
	cost = to_int(cost);
	if (ship->GetVehicleSize() == VS_YACHT)       cost *= 0.1;
  if (ship->GetVehicleSize() == VS_CRUISER)     cost *= 4;
  if (ship->GetVehicleSize() == VS_DREADNAUGHT) cost *= 10;
	if (who->GetCurrency(LocalCurrency) < cost) {
  	eventForce("speak It doesn't seem you have enough money for that.");
  	eventForce("speak I would charge you " + cost + " " + LocalCurrency + 
  	           " for shields of that size.");
  	return 1;
  }
  
  ship->SetShieldSystem(size);
  ship->RemoveDamagedSystem("shield");
  who->AddCurrency(LocalCurrency, -cost);
  eventForce("speak " + capitalize(arg) + " magical shields installed "
             "at a cost of " + cost + " " + LocalCurrency);
	return 1;
}

int eventSellWeapons(object who, string arg, string rest) {
	mixed cost;
	int size;
	object ship, wharf;
	switch (arg) {
		case "small" :
		  size = VW_SMALL;
		  break;
		case "medium":
		  size = VW_MEDIUM;
		  break;
		case "huge":
		  size = VW_HUGE;
		  break;
		case "devastating":
		  size = VW_DEVASTATING;
		  break;  
		default:
		  eventForce("speak Did you want small, medium, or huge, or "
		             "devastating weapons?");
		  return 1;
		  break;
		}
  ship = present(rest, wharf = load_object(Wharf));
  if (!ship) {
  	eventForce("speak Sorry, but I don't see " + rest + " docked at " +
  	           wharf->GetShort());
  	return 1;
  }
  if (ship->GetKeyname() == "dinghy") {
    eventForce("speak Any additional weight's going to sink her like a stone.");
    return 1;
  }
  if (size > ship->GetVehicleSize()) {
  	eventForce("speak That ship isn't big enough to handle " + arg + " weapons.  Sorry.");
  	return 1;
  }
  if (size > ship->GetVehicleSize()) {
  	eventForce("speak That ship isn't big enough to handle " + arg +
  	           " shields.  Sorry.");
  	return 1;
  }
  cost = size * 4000 * currency_rate(LocalCurrency) * WeaponModifier;
	cost = to_int(cost);
	if (ship->GetVehicleSize() == VS_YACHT)       cost *= 0.1;
  if (ship->GetVehicleSize() == VS_CRUISER)     cost *= 4;
  if (ship->GetVehicleSize() == VS_DREADNAUGHT) cost *= 10;
	if (who->GetCurrency(LocalCurrency) < cost) {
  	eventForce("speak It doesn't seem you have enough money for that.");
  	eventForce("speak I would charge you " + cost + " " + LocalCurrency + 
  	           " for weapons of that size.");
  	return 1;
  }  
  ship->SetWeaponSystem(size);
  ship->RemoveDamagedSystem("weapon");
  who->AddCurrency(LocalCurrency, -cost);
  eventForce("speak " + capitalize(arg) + " weapons installed "
             "at a cost of " + cost + " " + LocalCurrency);
	return 1;
}

int eventSellMasts(object who, string arg, string rest) {
	mixed cost;
	int size;
	object ship, wharf;
	switch (arg) {
		case "coastal" :
		  size = VM_COASTAL;
		  break;
		case "deep": case "deep-ocean":
		  size = VM_DEEP;
		  break;
		default:
		  eventForce("speak Did you want coastal or deep-ocean masts?");
		  return 1;
		  break;
		}
	if (size > LargestDrive) {
		eventForce("speak I don't sell anything that big.");
		return 1;
	}	
  ship = present(rest, wharf = load_object(Wharf));
  if (!ship) {
  	eventForce("speak Sorry, but I don't see " + rest + " docked at " + wharf->GetShort());
  	return 1;
  }
  if (ship->GetKeyname() == "dinghy") {
    eventForce("speak Any additional weight's going to sink her like a stone.");
    return 1;
  }
  if (size > ship->GetVehicleSize()) {
  	eventForce("speak That ship isn't big enough to handle " + arg +  " masts.  Sorry.");
  	return 1;
  }
	cost = size * 1000 * currency_rate(LocalCurrency) * DriveModifier;
	cost = to_int(cost);
	if (ship->GetVehicleSize() == VS_YACHT)       cost *= 0.1;
  if (ship->GetVehicleSize() == VS_CRUISER)     cost *= 4;
  if (ship->GetVehicleSize() == VS_DREADNAUGHT) cost *= 10;

	if (who->GetCurrency(LocalCurrency) < cost) {
  	eventForce("speak It doesn't seem you have enough money for that.");
  	eventForce("speak I would charge you " + cost + " " + LocalCurrency +  " for " + arg + " sailing masts.");
  	return 1;
  }
  ship->SetDriveSystem(size);
  ship->RemoveDamagedSystem("sails");
  who->AddCurrency(LocalCurrency, -cost);
  eventForce("speak " + capitalize(arg) + " sailing masts installed "
             "at a cost of " + cost + " " + LocalCurrency);
	return 1;
}

int eventSellSupplies(object who, string arg, string rest) {
	mixed cost;
	object ship, wharf;
	int amount;
	
  if (!amount = to_int(arg)) {
  	eventForce("speak How many supplies did you need me to sell you?");
  	return 1;
  }
  if (amount <= 0) {
  	eventForce("speak Cute, but no.");
  	return 1;
  	}
  
  cost = amount * currency_rate(LocalCurrency);
  cost = to_int(cost);
  if (who->GetCurrency(LocalCurrency) < cost) {
  	eventForce("speak It doesn't seem you have enough money for that.");
  	eventForce("speak I would charge you " + cost + " " + LocalCurrency + 
  	           " for " + arg + " supplies.");
  	return 1;
  } 
  ship = present(rest, wharf = load_object(Wharf));
  if (!ship) {
  	eventForce("speak Sorry, but I don't see " + rest + " docked at " +
  	           wharf->GetShort());
  	return 1;
  }
  if (ship->GetKeyname() == "dinghy") {
    eventForce("speak Any additional weight's going to sink her like a stone.");
    return 1;
  }
  ship->AddShipStores(amount);
  who->AddCurrency(LocalCurrency, -cost);
  eventForce("speak " + amount + " supplies delivered to " + rest + 
             " at a cost of " + cost + " " + LocalCurrency + "!");
	return 1;
}

int eventSellNavigation(object who, string arg, string rest) {
	mixed cost;
	int size;
	object ship, wharf;
	switch (arg) {
		case "partial" :
		  size = VSE_LOCAL;
		  break;
		case "full":
		  size = VSE_WIDE;
		  break;
		default:
		  eventForce("speak Did you want full or partial navigation equipment?");
		  return 1;
		  break;
		}
	if (size > LargestSensor) {
		eventForce("speak I don't sell anything that big.");
		return 1;
	}	
	ship = present(rest, wharf = load_object(Wharf));
  if (!ship) {
  	eventForce("speak Sorry, but I don't see " + rest + " docked at " +
  	           wharf->GetShort());
  	return 1;
  }
  if (ship->GetKeyname() == "dinghy") {
    eventForce("speak Any additional weight's going to sink her like a stone.");
    return 1;
  }
  if (size > ship->GetVehicleSize()) {
  	eventForce("speak That ship isn't big enough to handle " + arg +
  	           " navigation equipment.  Sorry.");
  	return 1;
  }
  cost = size * 500 * currency_rate(LocalCurrency) * SensorModifier;
	cost = to_int(cost);
	if (who->GetCurrency(LocalCurrency) < cost) {
  	eventForce("speak It doesn't seem you have enough money for that.");
  	eventForce("speak I would charge you " + cost + " " + LocalCurrency + 
  	           " for " + arg + " navigation equipment.");
  	return 1;
  }
 	if (ship->GetVehicleSize() == VS_YACHT)       cost *= 0.1;
  if (ship->GetVehicleSize() == VS_CRUISER)     cost *= 4;
  if (ship->GetVehicleSize() == VS_DREADNAUGHT) cost *= 10;
  ship->SetSensorSuite(size);
  ship->RemoveDamagedSystem("navigation");
  who->AddCurrency(LocalCurrency, -cost);
  eventForce("speak " + capitalize(arg) + " navigation gear installed "
             "at a cost of " + cost + " " + LocalCurrency);
	return 1;
}


int eventSell(object who, string args) {
  string what, thing, rest;
  object ship;
  mixed cost;
  sscanf(args, "%s %s %s", what, thing, rest);
  if (!what) {
  	eventForce("speak Ask me to sell what?");
  	eventForce("speak You can ask me to sell new <size> <name>");
  	eventForce("speak You can ask me to sell <size> shields for <ship>");
  	eventForce("speak You can ask me to sell <size> weapons for <ship>");
  	eventForce("speak You can ask me to sell <amount> supplies for <ship>");
  	eventForce("speak You can ask me to sell <size> masts for <ship>");
  	eventForce("speak You can ask me to sell <size> navigation for <ship>");
  	return 1;
  	}
  if (what == "new") {
  	eventNewShip(who, thing, rest);
  	return 1;
  	}
  if (!rest) {
  	eventForce("speak Sell what what for what ship?");
  	return 1;
  	}
  sscanf(rest, "for %s", rest);
  switch(thing) {
  	case "shields" :
  	  eventSellShields(who, what, rest);
  	  break;
  	case "weapons" : 
  	  eventSellWeapons(who, what, rest);
  	  break;
  	case "supplies":
  	  eventSellSupplies(who, what, rest);
  	  break;
  	case "masts" :
  	  eventSellMasts(who, what, rest);
  	  break;
  	case "navigation" :
  	  eventSellNavigation(who, what, rest);
  	  break;
  	default:
  	  eventForce("speak I'm not understanding.");
  	  break;
  	  }
	return 1;
}

int eventRepair(object who, string what) {
	object ship, wharf;
	int damage;
	mixed cost;
	if (!Wharf) {
		eventForce("speak I'm sorry, I seem to have misplaced my wharf.");
		CHAT_D->eventSendChannel(identify(this_object()), "error", 
		                         "No Wharf set by some dumbass.");
		return 1;
		}
	ship = present(what, wharf = load_object(Wharf));
	if (!ship) {
		eventForce("speak My agents can't find any ship by that name "
		           "in " + wharf->GetShort());
		return 1;
	}
	if (!vehiclep(ship)) {
		eventForce("speak Cute, but that's not a ship.");
		return 1;
	}
  if (ship->GetKeyname() == "dinghy") {
    eventForce("speak They're aren't no mending some things.");
    return 1;
  }
  damage = ship->GetMaxDamagePoints() - ship->GetDamagePoints();
  if (!damage) {
  	eventForce("speak But that ship is not damaged!");
  	return 1;
  }
  cost = damage * RepairModifier * 0.01 * currency_rate(LocalCurrency);
  cost = to_int(cost);
  if (who->GetCurrency(LocalCurrency) < cost) {
  	eventForce("speak It doesn't seem you have enough money for that.");
  	eventForce("speak I would charge you " + cost + " " + LocalCurrency + 
  	           " to repair that vessel.");
  	return 1;
  }
  who->AddCurrency(LocalCurrency, -cost);
  eventForce("speak Thank you, " + who->GetCapName() + ", I have "
             "charged you " + cost + " " + LocalCurrency + " and " 
             "have repaired " + ship->GetShort() + ".");
  ship->AddDamagePoints(damage);
	return 1;
}

void eventGreet(object who) {
  eventAsk(who, " ");
}

mixed eventAsk(object who, string args) {
	string action, what, ship;	
	sscanf(args, "%s %s", action, what); 
	
	if (!what) {
		eventForce("speak Would you like me to sell something or repair a ship?");
		eventForce("speak Did you want me to sell or repair?");
		eventForce("speak Ask me to sell what?");
  	eventForce("speak You can ask me to sell new <size> <name>");
  	eventForce("speak You can ask me to sell <size> shields for <ship>");
  	eventForce("speak You can ask me to sell <size> weapons for <ship>");
  	eventForce("speak You can ask me to sell <amount> supplies for <ship>");
  	eventForce("speak You can ask me to sell <size> masts for <ship>");
  	eventForce("speak You can ask me to sell <size> navigation for <ship>");
  	eventForce("speak You can ask me to salvage <ship>");
  	eventForce("speak You can ask me to appraise <ship> if you're interested in selling.");
  	eventForce("speak You can ask me to buy <ship> if you're sure you want to sell it to me.");
	  return 1;
	}
	switch(action) {
		case "sell"   :
		  eventSell(who, what);
		  break;
		case "repair" :
		  eventRepair(who, what);
		  break;
		case "salvage" :
		  eventSalvage(who, what);
		  break;
		case "appraise":
		  eventAppraiseShip(who, what);
		  break;
		case "buy":
		  eventBuyShip(who, what);
		  break;
		default:
		  eventForce("speak Did you want me to sell, repair, appraise, salvage, or buy?");
  	  eventForce("speak You can ask me to sell new <size> <name>");
  	  eventForce("speak You can ask me to sell <size> shields for <ship>");
  	  eventForce("speak You can ask me to sell <size> weapons for <ship>");
  	  eventForce("speak You can ask me to sell <amount> supplies for <ship>");
  	  eventForce("speak You can ask me to sell <size> masts for <ship>");
  	  eventForce("speak You can ask me to sell <size> navigation for <ship>");
  	  eventForce("speak You can ask me to salvage <ship>");
  	  eventForce("speak You can ask me to appraise <ship> if you're interested in selling.");
  	  eventForce("speak You can ask me to buy <ship> if you're sure you want to sell it to me.");
		  break;
		}
	return 1;
}
