/*  Invasion object.  Controls who, what, and where.
 *  Duuktsaryth  10-03-97
 */
#include <lib.h>

inherit LIB_DAEMON;

private mapping Invaders;
private mapping Messages;
private string PlayerTitle;
private string Leader;
private string Domain;
private object *invasion_objects;
private object leader_object;
private string InvasionLocation;

string SetPlayerTitle(string);
string GetPlayerTitle();
mapping SetMessages(mapping);
string GetMessage(string);
mapping SetInvaders(mapping);
mapping GetInvaders();
string SetStartLocation(string);
string GetStartLocation();
string SetLeader(string);
string GetLeader();
string SetDomain(string);
string GetDomain();
object *AddInvader(object);
object *RemoveInvader(object);
object *GetInvaderObjects();
object SetLeaderObject(object);
object GetLeaderObject();

static void create() {
  SetNoClean(1);
  Leader = "";
  Domain = "";
  Invaders = ([ ]);
  InvasionLocation = "/domains/haven/room/gate";
  invasion_objects = ({ });
  leader_object = 0;
  Messages = ([ ]);
 }

/*  Data Functions */

mapping SetMessages(mapping mp) {
  return (Messages = mp);
  }

string GetMessage(string args) {
  return (Messages[args]);
  }

object *GetInvaderObjects() {
  invasion_objects = filter(invasion_objects, (: $1 :) );
  return (invasion_objects);
  }

object *AddInvader(object arg) {
  return (invasion_objects += ({ arg }) );
  }

object *RemoveInvader(object arg) {
  return (invasion_objects -= ({ arg }) );
  }

object SetLeaderObject(object who) {
  return (leader_object = who);
  }

object GetLeaderObject() {
  return (leader_object);
  }

mapping SetInvaders(mapping args) {
  return (Invaders = args);
 }

mapping GetInvaders() {
  return (Invaders);
 }

string SetLeader(string arg) {
  return (Leader = arg);
  }

string GetLeader() {
 return (Leader);
  }

string SetDomain(string arg) {
  return (Domain = arg);
  }

string GetDomain() {
 return (Domain);
  }

string SetStartLocation(string arg) {
  return (InvasionLocation = arg);
 }

string GetStartLocation() {
  return (InvasionLocation);
 }

string SetPlayerTitle(string args) {
  return (PlayerTitle = args);
  }

string GetPlayerTitle() {
  return (PlayerTitle);
  }
