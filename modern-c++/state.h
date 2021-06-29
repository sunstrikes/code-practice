//
// Created by Sun,Minqi on 2021/6/29.
//
#pragma once

#include "util.h"
// back-end
#include <boost/msm/back/state_machine.hpp>
//front-end
#include <boost/msm/front/state_machine_def.hpp>
#include <boost/msm/front/functor_row.hpp>

namespace state {
    namespace msm = boost::msm;
    namespace mpl = boost::mpl;
    using namespace msm::front;

    std::vector<std::string> state_names{
            "off hook",
            "connecting",
            "connected",
            "on hold",
            "destroyed"
    };

// transitions/events
    struct CallDialed {
    };
    struct HungUp {
    };
    struct CallConnected {
    };
    struct PlacedOnHold {
    };
    struct TakenOffHold {
    };
    struct LeftMessage {
    };
    struct PhoneThrownIntoWall {
    };

    struct PhoneStateMachine : state_machine_def<PhoneStateMachine> {
        bool angry{true}; // start with false

        struct OffHook : msm::front::state<> {
        };

        struct Connecting : msm::front::state<> {
            template<class Event, class FSM>
            void on_entry(Event const &evt, FSM &) {
                std::cout << "We are connecting..." << std::endl;
            }
            // also on_exit
        };

        struct Connected : msm::front::state<> {
        };
        struct OnHold : msm::front::state<> {
        };
        struct PhoneDestroyed : msm::front::state<> {
        };

        struct PhoneBeingDestroyed {
            template<class EVT, class FSM, class SourceState, class TargetState>
            void operator()(EVT const &, FSM &, SourceState &, TargetState &) {
                std::cout << "Phone breaks into a million pieces" << std::endl;
            }
        };

        struct CanDestroyPhone {
            template<class EVT, class FSM, class SourceState, class TargetState>
            bool operator()(EVT const &, FSM &fsm, SourceState &, TargetState &) {
                return fsm.angry;
            }
        };

        //状态转换表
        //Row<SOURCE,EVENT,TARGET,none,none>
        //Row<SOURCE,EVENT,TARGET,ACTION,GUARD>
        struct transition_table : mpl::vector<
                Row<OffHook, CallDialed, Connecting>,
                Row<Connecting, CallConnected, Connected>,
                Row<Connected, PlacedOnHold, OnHold>,
                Row<OnHold, PhoneThrownIntoWall, PhoneDestroyed,
                        PhoneBeingDestroyed, CanDestroyPhone>
        > {
        };
        //初始状态定义
        typedef OffHook initial_state;

        // what happens if there's nowhere to go
        template<class FSM, class Event>
        void no_transition(Event const &e, FSM &, int state) {
            std::cout << "No transition from state " << state_names[state]
                      << " on event " << typeid(e).name() << std::endl;
        }
    };


}