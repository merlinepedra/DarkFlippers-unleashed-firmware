#pragma once

#include <gui/view.h>
#include "assets_icons.h"
#include <input/input.h>
#include <gui/elements.h>
#include <gui/icon.h>
#include <subghz/types.h>
#include "../subbrute_custom_event.h"

typedef void (*SubBruteAttackViewCallback)(SubBruteCustomEvent event, void* context);
typedef struct SubBruteAttackView SubBruteAttackView;

void subbrute_attack_view_set_callback(
    SubBruteAttackView* instance,
    SubBruteAttackViewCallback callback,
    void* context);
SubBruteAttackView* subbrute_attack_view_alloc();
void subbrute_attack_view_free(SubBruteAttackView* instance);
View* subbrute_attack_view_get_view(SubBruteAttackView* instance);
void subbrute_attack_view_set_current_step(SubBruteAttackView* instance, uint64_t current_step);
uint64_t subbrute_attack_view_get_current_step(SubBruteAttackView* instance);
void subbrute_attack_view_init_values(
    SubBruteAttackView* instance,
    uint8_t index,
    uint64_t max_value,
    uint64_t current_step,
    bool is_attacking);
void subbrute_attack_view_stop_worker(SubBruteAttackView* instance);
bool subbrute_attack_view_can_send(SubBruteAttackView* instance);
void subbrute_attack_view_start_worker(
    SubBruteAttackView* instance,
    uint32_t frequency,
    FuriHalSubGhzPreset preset,
    const char* protocol_name);
bool subbrute_attack_view_transmit(SubBruteAttackView* instance, const char* payload);
bool subbrute_attack_view_is_worker_running(SubBruteAttackView* instance);