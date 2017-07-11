/*
 * Runed obsidian axe
 * mediocre damage stats,
 * but deals additional damage based upon magic boost skill.
 * practical mages deal some additional magic damage
 */
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

int SetupProc();

static void create() {
  item::create();
  SetKeyName("obsidian axe");
  SetId( ({ "axe" }) );
  SetAdjectives( ({ "runed", "obsidian" }) );
  SetShort("a runed obsidian axe");
  SetLong(
    "This axe appears to have been carved from"
    " a solid chunk of obsidian. Dark runes running up the"
    " the shaft of the weapon seem to twist and distort"
    " with the light."
  );
  SetHands(1);
  SetClass(15);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(1000);
  SetValue(1600);
  SetMass(200);
  SetMaterials( ({ "natural" }) );
  SetRepairDifficulty(80);
  SetProperty("magic",
    "This axe has been embued with the power"
    " to channel its wielder's natural elemental magic."
  );
  SetProperty("history",
    "This axe was crafted by some fell smith of the "
    " plane of fire."
  );
  SetWield( (:SetupProc:) );
}

// do elemental damage if player deserves it.
int eventStrike(object who) {
  int amount = 0;

  if (GetProperty("hasMagicBoost") == 1) {
      amount = random(GetProperty("MagicBoostAmount"));
      message("action", 
        environment()->GetCapName() + "'s axe " +
        GetProperty("MagicBoostDesc"),
      environment(environment()) );
      return (item::eventStrike(who) + amount);
  }
      return (item::eventStrike(who));
}

// called when wielded, so all this junk isn't checked on every strike.
int SetupProc() {
  int hasMagicBoost = 0;
  int MagicBoostType = 0;
  int MagicBoostAmount = 0;
  object wielder = this_player();
  string MagicBoostDesc = "";

  if ( wielder->GetSkill("fire magic") ) {
    hasMagicBoost = 1;
    MagicBoostType = HEAT;
    MagicBoostAmount = wielder->GetSkill("fire magic")["level"] * 3 / 4;
    MagicBoostDesc = "%^RED%^surges with flame%^RESET%^";
  } else if ( wielder->GetSkill("ice magic") ) {
    hasMagicBoost = 1;
    MagicBoostType = COLD;
    MagicBoostAmount = wielder->GetSkill("ice magic")["level"] * 3 / 4;
    MagicBoostDesc = "%^CYAN%^exudes a bitter frost!%^RESET%^";
  } else if ( wielder->GetSkill("shock magic") ) {
    hasMagicBoost = 1;
    MagicBoostType = SHOCK;
    MagicBoostAmount = wielder->GetSkill("shock magic")["level"] * 3 / 4;
    MagicBoostDesc = "%^YELLOW%^spits sparks of lightning%^RESET%^";
  } else if ( wielder->GetSkill("poison magic") ) {
    hasMagicBoost = 1;
    MagicBoostType = POISON;
    MagicBoostAmount = wielder->GetSkill("poison magic")["level"] * 3 / 4;
    MagicBoostDesc = "%^GREEN%^drips with venom%^RESET%^";
  // give silly practical mages a bone.
  // only half value, though.
  } else if ( wielder->GetSkill("practical magic") ) {
    hasMagicBoost = 1;
    MagicBoostType = MAGIC;
    MagicBoostAmount = wielder->GetSkill("practical magic")["level"] * 3 /8;
    MagicBoostDesc = "%^MAGENTA%^shimmers faintly with arcane energy%^RESET%^";
    if (MagicBoostAmount > 38) {
      MagicBoostAmount = 38;
    }
  }
  // player is sucky non-mage or untrained mage
  if (!hasMagicBoost || !MagicBoostAmount) {
    SetProperty("hasMagicBoost","");
    send_messages( ({"wield"}), 
      "$agent_name $agent_verb an obsidian axe.",
      wielder,0, environment(environment())
    );
    return 1;
  }
  // don't let amount get over 75
  if (MagicBoostAmount > 75) {
    MagicBoostAmount = 75;
  }
  SetProperty("hasMagicBoost",1);
  SetProperty("MagicBoostType",MagicBoostType);
  SetProperty("MagicBoostAmount",MagicBoostAmount);
  SetProperty("MagicBoostDesc",MagicBoostDesc);
  // wield message
  send_messages( ({"wield"}), 
    "$agent_possessive_noun axe " +GetProperty("MagicBoostDesc") +
    " as $agent_nominative $agent_verb it.", wielder, 0, environment(environment())
  );
  return 1;
}

