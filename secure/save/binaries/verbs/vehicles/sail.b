MUDB	�I��L� secure/include/global.h secure/include/lib.h secure/include/dirs.h include/vehicle.h include/damage_types.h secure/include/daemons.h secure/include/dirs.h  verbs/vehicles/sail.c�  �!       X   ��@@��@@����|  �  �  �  �  �  �  �  �            !   ?     -   ,  , 	, 
, , /y
byb�  .�  .�  .? .�  .��� @_ ?.�  .?
�� ./y
bybbb  b  b� b?   b?  ?  ?
?
 ? @V � b?p ? .Sb?
 b� @\ �
  
 �"! @\�# C $�c%c?
 c&c� c'c �
  
 ( )cql ? 	 �+* @` �,*��c@� b�#  ? -�c.c?cql �+* 22 ?q�  �/�+* fc 0�c1cy@�qt �@� dq� +� �  �"�2 3c �4@B�q e � �"5 �"6 .q �"7 �4@B�q e S �"8 �"9 �;: 5 2      2    3    P   , Q    _   C `    d   a �@2  ? �"6 ? �"< .�= ?
>�� ./-   /   t*       �� 	�   t! -   �w     �%%���55$r �!Ȣ�l��
!�fx2@�C �F ���!8�B@�qd�иH� T��j 4g|�8i��B@,!`O �B@�O 09!�Qx8!<�4p4��� �B@�,4rL9!\� d) l�`;!p;!����T�'!D;!t�8�@@��ܙh�@@����@@�;!X�B@��@@�@@�� �;!��B@T,!��t�?@        lib/special/verb.c verbs/vehicles/sail.c secure/include/global.h secure/include/lib.h secure/include/dirs.h include/vehicle.h include/damage_types.h secure/include/daemons.h sail dock STR Sail the ship where??{ Syntax: <sail DIRECTION>
Moves your ship towards the direction you specify. 
See also: climb, enter, jump, go, <help ships> GetSleeping You are asleep! GetParalyzed You are paralyzed! GetStaminaPoints You are too tired. You are nowhere. PROP_VEHICLE GetProperty You are not in a vehicle! CanPilot GetCrystals) You don't have enough stores to sail out! CanGo GetShipEnemies GetPilot GetSailingDifficulty GetVehicleSize /daemon/weather	 GetDomain
 GetRaining* Sailing in such weather is more difficult!
 eventPrint GetTestChar Sailing Difficulty:   (base  , Size:  , Rain:  Yes No sailing GetSkillLevel eventCheckSkill	 success:   eP->sailing:  AddStaminaPoints! $agent_name $agent_verb the ship  .
 GetCapName  hits some floating debris. eventReceiveDamage+ The ship fails to respond to your commands. The ship doesn't move.' The ship hits a large amount of debris.9 %^BOLD%^RED%^You've managed to damage the sails!%^RESET%^2 %^BOLD%^RED%^The sails have been damaged!%^RESET%^ sails AddDamagedSystem% You fail to evade the ship's enemies. AddCrystals eventGo create do_sail_str can_sail_str #global_init#��       
    x  �              x  Q  d  z  {  
|  }  ~  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  	�  
�  �  �  �  	�  �  	�  �  �  �  �  	�  �  
�   �  !�  �  �  �  �  �  �  �  �  �  �  �  �  	�  �  	�  �  	�  	�  ?�  �  �  �  
�  �  w    