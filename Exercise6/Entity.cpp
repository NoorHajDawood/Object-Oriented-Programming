#include "Entity.h"

/*-------------------------------------------------------------------------------*/
/*------------------------------ENTITY-------------------------------------------*/
void Entity::move(float offX, float offY)
{
	m_pos.changePos(offX, offY);
}
/*-------------------------------------------------------------------------------*/
void Entity::print(ostream & out) const
{
	m_pos.print(out);
}
/*-------------------------------------------------------------------------------*/
ostream & operator<<(ostream & out, const Entity & entity)
{
	entity.print(out);
	return out;
}
/*-------------------------------------------------------------------------------*/
/*------------------------------PLAYER-------------------------------------------*/
void Player::move(float offX, float offY)
{
	m_pos.changePos(2.f * offX, 2.f * offY);
}
/*-------------------------------------------------------------------------------*/
void Player::print(ostream & out) const
{
	out << "Player Info:" << endl;
	out << "Position: ";
	Entity::print(out);
	out << "Name: " << m_name << endl;
}
/*-------------------------------------------------------------------------------*/
ostream & operator<<(ostream & out, const Player & player)
{
	player.print(out);
	return out;
}
/*-------------------------------------------------------------------------------*/
/*-----------------------------WARLOCK-------------------------------------------*/
void Warlock::move(float offX, float offY)
{
	m_pos.changePos(4.f * offX, 4.f * offY);
}
/*-------------------------------------------------------------------------------*/
void Warlock::print(ostream & out) const
{
	out << "Warlock Info:" << endl;
	out << "Position: ";
	Entity::print(out);
}
/*-------------------------------------------------------------------------------*/
ostream & operator<<(ostream & out, const Warlock & war)
{
	war.print(out);
	return out;
}
/*-------------------------------------------------------------------------------*/
/*-----------------------------MONSTER-------------------------------------------*/
void Monster::print(ostream & out) const
{
	out << "Monster Info:" << endl;
	out << "Position: ";
	Entity::print(out);
	out << "Rank: " << m_rank << endl;
}
/*-------------------------------------------------------------------------------*/
ostream & operator<<(ostream & out, const Monster & mon)
{
	mon.print(out);
	return out;
}

/*-------------------------------------------------------------------------------*/
/*-----------------------------SPECIALPLAYER-------------------------------------*/
void SpecialPlayer::print(ostream & out) const
{
	Player::print(out);
	out << "Weapon Strength: " << m_weaponStrength << endl;
}
/*-------------------------------------------------------------------------------*/
ostream & operator<<(ostream & out, const SpecialPlayer & sp)
{
	sp.print(out);
	return out;
}
/*-------------------------------------------------------------------------------*/

