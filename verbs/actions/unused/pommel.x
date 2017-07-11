// mahkefel 2011
// pommel, sword slinging move
//   essentially pistol whipping
//   dazes a bit or on good success knocks someone out.

inherit LIB_ACTION

static void create() {
::create()
SetVerb("pommel")
SetRules("LIV","")
SetHelp("
"Syntax: pommel, pommel LIV

"
"You strike the target in the back of the head with your sword, "
"disorienting them or possibly knocking them unconcious.")
SetStaminaCost(100)
SetRequiredWeapon("slash")
SetRequiredSkills( ([
"sword slinging" : 150,
"slash combat" : 150,
]) )
}

mixed can_pommel() {
if (!this_player()->GetInCombat()) { return "But you fight no one!"; }
return CanAction(this_player())
}

mixed can_pommel_liv() {
return CanAction(this_player())
}

mixed do_pommel_liv(object target) {
return eventAction(this_player(), ({target}) )
}

mixed do_pommel() {
return eventAction(this_player(), this_player()->GetEnemies() )
}

int eventAttack(object who, object* targets) {
int result

if(who->GetTestChar()) debug ("invoke message")
send_messages("whip","$agent_name%^BOLD%^YELLOW%^ $agent_verb "
"%^RESET%^the pommel of $agent_possessive "+weapon->GetKeyName()+"
"towards $target_possessive_noun face!",
who, 0, environment())

// this needs a... fairly low chance. Technically, it's an instakill
//   when used by anyone with any stealth at all.
// maybe have a lesser "ow, that hurt, fuck you" success and a low chance
// go to sleep?
int pro, con
pro = who->GetSkillLevel("slash combat")/4
pro = who->GetStatLevel("strength")/4
pro = who->GetLuck()

con = target->GetSkillLevel("durability")
con += target->GetStatLevel("wisdom")/2
con += target->GetLuck()

result = who->eventCheckSkill("sword slinging", con, pro, 100)

if (result > 0 ) {
send_messages( ({"pop"}), "$agent_name%^BOLD%^YELLOW%^ "
"$agent_verb%^RESET%^ $target_name on the back of "
"$target_possessive skull!",
target, who, environment(who) )

target->AddDelayAction(who->GetSkillLevel("sword slinging")/10 + who->GetSkillLevel("disorient")/4)
target->AddParalyzed(2)


if (random(target->GetStatLevel("durability"))*2 < who->GetStatLevel("strength")) {
send_messages( ({"collapse"}), "$target_possessive_noun%^BOLD%^YELLOW%^ "
"lights%^RESET%^ go out, and $target_objective $target_verb in a "
"heap!",
who, target, environment(who) )

target->RemoveEnemy(who)
who->RemoveEnemy(target)
target->ResetCurrentEnemy()
target->ResetCurrentEnemy()
// have it twice in some other file, copying that.
target->SetPosition(1)
// replace with constant
target->SetSleeping(random(3)+2)
}
} else {
// clangs harmlessly off dude's thick skull.
// start combat
send_messages( ({"clang"}), "$agent_possessive_noun "+weapon->GetKeyName()+
"%^YELLOW%^clangs%^RESET%^harmlessly off of $target_possessive_noun "
"thick skull!",
who, target, environment(who) )
weapon->eventDeteriorate(DAMAGE_TYPE_BLUNT)
// i find this hilarious.
}

return 1
}

>
> less buckle.c
inherit LIB_ACTION

static void create() {
::create()
SetVerb("buckle")
SetRules("LIV", "")
SetHelp("Not content to cower behind a gilded shield, a novice "
"swashbuckler can bash at his opponents weapon, attempting to "
"shatter it. It is obviously difficult to perform this manuever "
"without holding a shield in one of your hands.")
SetStaminaCost(30)
SetRequiredWeapon("shield")
//shield is not a weapon type. things should be overridden so this doesn't tgo fubar
SetRequiredSkills( ([
"swashbuckling" : 50,
]) )
}

mixed can_buckle() {
if (!this_player()->GetInCombat()) { return "buckle who?"; }
return CanAction(this_player())
}

mixed can_buckle_liv() {
return CanAction(this_player())
}

mixed do_buckle_liv(object target) {
return eventAction(this_player(), target)
}
/verbs/actions/buckle.c (1-33 29%):

mixed do_buckle() {
return do_buckle_liv(this_player()->GetCurrentEnemy())
}

int eventAttack(object who, object target) {
int result, damage
int pro, con
object weapon, buckler
object *pretties

if (!target) debug("Buckle found no target!")

if (who->GetProperty("action_debug")) debug("buckling")

buckler = GetAnyWeapon(who)
if (!buckler) {
if (who->GetTestChar()) debug("ain't no shield")
who->eventPrint("you find yourself mysteriously unshielded!")
return 1
}

if (target->GetWielded() == ({ }) ) {
who->eventPrint(capitalize(target->GetKeyName()) + " has nothing for you to smash!")
return 1
//TODO: consider shield bashing atthis point. CON: moar work.
}
weapon = target->GetWielded()[random(sizeof(target->GetWielded()))]


pro = who->GetSkillLevel("parry")/2
pro += who->GetStatLevel("coordination")/2
pro += who->GetLuck()
/verbs/actions/buckle.c (34-66 60%):

con = target->GetSkillLevel("parry")
con += who->GetStatLevel("agility")/2
con += who->GetLuck()

result = who->eventSkillCheck("swashbuckling", con, pro, 100)

if (who->GetProperty("action_debug")) debug("thrust sendmessage")
send_messages( ({ "thrust" }),
"$agent_name%^BOLD%^CYAN%^ $agent_verb%^RESET%^ $agent_possessive shield at "
"$target_possessive_noun " +weapon->GetKeyName() + "!",
who, target, environment(who))

if (result == -1) {
if (who->GetProperty("action_debug")) debug("fumble sendmessage")
send_messages( ({ "sieze","bring" }), "$target_name $target_verb the opportunity, and "
"$target_verb $target_possessive weapon %^CYAN%^crashing%^RESET%^ down on "
"$agent_possessive_noun "+buckler->GetKeyName()+".",
who, target, environment(who))
buckler->eventDeteriorate(weapon->GetDamageType())
return 1
}

if (result = 0) {
if (who->GetProperty("action_debug")) debug("miss sendmessage")
send_messages( ({ "knock" }),
"$agent_name %^CYAN%^$agent_verb%^RESET%^ $target_possessive_noun "
+ weapon->GetKeyName() + " away harmlessly.",
who, target, environment(who))
return 1
}

if (who->GetProperty("action_debug")) debug("hit sendmessage")
/verbs/actions/buckle.c (67-99 91%):
// blow has landed
send_messages("",
"$agent_possessive_noun "+buckler->GetKeyName()+" connects with $target_possessive_noun "
+weapon->GetKeyName()+" with a loud %^BOLD%^CYAN%^buckle!%^RESET%^",
who, target, environment(who) )
weapon->eventDeteriorate(BLUNT)
return 1
}

