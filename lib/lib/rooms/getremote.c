#include <position.h>

varargs string GetRemoteDescription(string where, int noCheckLight) {
    // Added by Tim Morris aka Morgoth@Haven on 12/18/98. Returns the
    // description of the room with the file path 'where' including
    // short description, obvious exits, long description, room inventory
    // and poison gas. Also takes into account light levels of the target room
    object env;
    mixed tmp;
    string *shorts;
    string desc, key;
    int brief = 0;
    int i, maxi, val;
    mapping lying, sitting, standing;
    object *obs;
    int *vis;

    if(!(env = find_object(where))) {
        env = load_object(where);
    }
    if(!env) {
        desc = "You are looking at nowhere!";
        return desc;
        }
        if(!noCheckLight)
        {
            if( this_player()->GetBlind() ) {
            desc = "You are blind!";
                return desc;
            }
                vis = this_player()->GetLightSensitivity();
            if(vis) {
                if( this_player()->GetVisionBonus() > 0 )
                    vis[1] += this_player()->GetVisionBonus();
                else if( this_player()->GetVisionBonus() < 0 )
                    vis[0] += this_player()->GetVisionBonus();
                if( env->GetEffectiveLight() < vis[0] ) {
                    desc = "It is much too dark to see.";
                    return desc;
                    }
                else if( env->GetEffectiveLight() > vis[1] ) {
                    desc = "It is mich too %^BOLD%^YELLOW%^bright"
                            "%^RESET%^ to see.";
                    return desc;
                    }
                }
    }
        desc = (string)env->GetObviousExits() || "";
    desc = capitalize(env->GetInternalShort() || env->GetShort() || "")
        + " [" + desc + "]\n";
    desc += (env->GetInternalLong() || env->GetLong() || "");
    desc += "\n";
    lying = ([]);

    shorts = map(filter(all_inventory(env),
                function(object ob) {
                    if( living(ob) ) return 0;
                    if( (int)ob->GetInvis(this_object()) )
                        return 0;
                    if( (int)ob->isFreshCorpse() ) return 0;
                        return 1;
                    }), (: (string)$1->GetShort() :));
    foreach(string shrt in shorts) {
        if( shrt )
            lying[shrt]++;
        }
    for(i=0, maxi = sizeof(shorts = keys(lying));
        i<maxi; i++) {
        key = shorts[i];
        val = lying[shorts[i]];
        if( val < 2 ) {
            if( !desc ) desc = "%^MAGENTA%^" +
                key + "%^RESET%^MAGENTA%^";
            else desc += key + "%^RESET%^MAGENTA%^";
            }
        else {
            if( !desc ) desc = "%^MAGENTA%^" +
               consolidate(val, key) +
                "%^RESET%^MAGENTA%^";
            else desc += consolidate(val, key) +
                "%^RESET%^MAGENTA%^";
            }
        if( i == maxi - 1 ) {
            if( maxi > 1 || val >1 )
                desc += " are here.%^RESET%^\n";
            else desc += " is here.%^RESET%^\n";
            }
        else if( i == maxi - 2 ) {
            if( maxi == 2 )
                desc += " and ";
            else
                desc += ", and ";
            }
        else desc += ", ";
        }
    lying = ([]);
    sitting = ([]);
    standing = ([]);
    obs = ({});
    key = 0;
    val = 0;

    obs = filter(all_inventory(env), function(object ob) {
        if( (int)ob->GetInvis(this_object()) ) return 0;
        if( living(ob) ) return 1;
        if( (int)ob->isFreshCorpse() )
            return 1;
        }) - ({ this_object() });
    maxi = sizeof(shorts = map(obs, (: (string)$1->GetHealthShort() :)));
    foreach(object liv in obs) {
        string s = (string)liv->GetHealthShort();
        int pos = (int)liv->GetPosition();
        if( !s ) continue;
        if( creatorp(liv) || pos == POSITION_STANDING) standing[s]++;
        else if( pos == POSITION_LYING || (int)liv->isFreshCorpse() )
            lying[s]++;
        else if( pos == POSITION_SITTING ) sitting[s]++;
        else lying[s]++;
        }
    if( !desc )
        tmp = "";
    else
        tmp = desc;
    desc = "";
    foreach(key, val in lying) {
        if( val<2 ) desc += capitalize(key) + "%^RESET%^ is lying down.";
        else desc += capitalize(consolidate(val, key)) +
           "%^RESET%^ are lying down.";
        desc += "\n";
        }
    foreach(key, val in sitting) {
        if( val<2 )
            desc += capitalize(key) + "%^RESET%^ is sitting down.";
        else desc += capitalize(consolidate(val, key)) +
            "%^RESET%^ are sitting down.";
        desc += "\n";
        }
    foreach(key, val in standing) {
        if( val<2 )
           desc += capitalize(key) + "%^RESET%^ is standing here.";
        else desc += capitalize(consolidate(val, key)) +
           "%^RESET%^ are standing here.";
           desc += "\n";
        }
    if( env->GetPoisonGas() > 5) 
        desc += "%^ORANGE%^There is a cloud of poison gas here!";
    if( tmp )
        desc = tmp + desc;
    return desc;
    }
