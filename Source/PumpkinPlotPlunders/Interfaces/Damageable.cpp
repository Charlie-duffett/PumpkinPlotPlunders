// Fill out your copyright notice in the Description page of Project Settings.


#include "Damageable.h"

// Add default functionality here for any IDamageable functions that are not pure virtual.
void IDamageable::DealDamage(float DamageAmount)
{
}

UPrimitiveComponent* IDamageable::GetHitboxComponent()
{
	return nullptr;
}
