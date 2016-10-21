class ArtilleryStateMachine {
    list = "ALIVE_sup_artillery_stateMachine_list";

    class Idle {
        onState = "";
        onStateEntered = "";
        onStateLeaving = "";

        class HasFireMission {
            targetState = "Active";
            condition = "[_this, 'hasFireMission'] call ALIVE_fnc_artillery";
            onTransition = "";
        };
    };

    class Active {
        onState = "";
        onStateEntered = "[_this, 'onActive'] call ALIVE_fnc_artillery";
        onStateLeaving = "";

        class InRange {
            targetState = "Execute";
            condition = "[_this, 'inRange'] call ALIVE_fnc_artillery";
            onTransition = "";
        };

        class NotInRange {
            targetState = "Pack";
            condition = "!([_this, 'inRange'] call ALIVE_fnc_artillery)";
            onTransition = "";
        };
    };

    class Pack {
        onState = "";
        onStateEntered = "[_this, 'onPack'] call ALIVE_fnc_artillery";
        onStateLeaving = "";

        class Packed {
            targetState = "Move";
            condition = "[_this, 'hasPacked'] call ALIVE_fnc_artillery";
            onTransition = "";
        };
    };

    class Move {
        onState = "";
        onStateEntered = "[_this, 'onMove'] call ALIVE_fnc_artillery";
        onStateLeaving = "";

        class InPosition {
            targetState = "Unpack";
            condition = "[_this, 'inPosition'] call ALIVE_fnc_artillery";
            onTransition = "";
        };

        class Abort {
            targetState = "ReturnToBase";
            condition = "!([_this, 'hasFireMission'] call ALIVE_fnc_artillery)";
            onTransition = "";
        };
    };

    class Unpack {
        onState = "";
        onStateEntered = "[_this, 'onUnpack'] call ALIVE_fnc_artillery";
        onStateLeaving = "";

        class Unpacked {
            targetState = "Execute";
            condition = "[_this, 'hasUnpacked'] call ALIVE_fnc_artillery";
            onTransition = "";
        };
    };

    class Execute {
        onState = "";
        onStateEntered = "[_this, 'onExecute'] call ALIVE_fnc_artillery";
        onStateLeaving = "";

        class Fire {
            targetState = "Fire";
            condition = "[_this, 'fireNextRound'] call ALIVE_fnc_artillery";
            onTransition = "";
        };

        class Abort {
            targetState = "ReturnToBase";
            condition = "!([_this, 'hasFireMission'] call ALIVE_fnc_artillery)";
            onTransition = "";
        };
    };

    class Fire {
        onState = "";
        onStateEntered = "[_this, 'onFire'] call ALIVE_fnc_artillery";
        onStateLeaving = "";

        class FireMissionComplete {
            targetState = "ReturnToBase";
            condition = "[_this, 'isFireMissionComplete'] call ALIVE_fnc_artillery";
            onTransition = "";
        };

        class Fired {
            targetState = "FireDelay";
            condition = "[_this, 'isFireMissionDelayed'] call ALIVE_fnc_artillery";
            onTransition = "";
        };
    };

    class FireDelay {
        onState = "";
        onStateEntered = "";
        onStateLeaving = "";

        class FireMissionComplete {
            targetState = "ReturnToBase";
            condition = "[_this, 'isFireMissionComplete'] call ALIVE_fnc_artillery";
            onTransition = "";
        };

        class Continue {
            targetState = "Fire";
            condition = "[_this, 'fireNextRound'] call ALIVE_fnc_artillery";
            onTransition = "";
        };
    };

    class ReturnToBase {
        onState = "";
        onStateEntered = "[_this, 'onReturnToBase'] call ALIVE_fnc_artillery";
        onStateLeaving = "";

        class AtBase {
            targetState = "Idle";
            condition = "[_this, 'inPosition'] call ALIVE_fnc_artillery";
            onTransition = "";
        };
    };
};
