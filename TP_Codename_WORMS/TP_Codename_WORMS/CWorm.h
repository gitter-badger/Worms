//
//  CWorm.h
//
//  Created by Jessy Desjardins on 2014-11-11.
//  Copyright (c) 2014 Jessy Desjardins. All rights reserved.
//

#ifndef TP_Codename_WORMS_CWorm_h
#define TP_Codename_WORMS_CWorm_h


/*!
@CWorm
@Classe permettant la cr�ation de la classe des Worm
*/
class CWorm : public CEntity{
private:
	string m_strName;
	int m_iLife; //Donn�e repr�sentant la vie actuelle du worm
	CSprite* m_pSprite;//Sprite du worm
	
public:
	/*!
	@Constructeur
	@Description: Permet d'initialiser les donn�es membres
	 @param _iLifeMax : la vie maximum du worm
	 @param _pSprite : le sprite du worm
	 @param _RectPos : la position du sprite
	@Classe h�ritant de CEntity
	*/
	CWorm(string _Name, CSprite* _pSprite, SDL_Rect _RectPos) :CEntity(_RectPos){
		m_strName = _Name;
		m_pSprite = _pSprite;
		m_pSprite->setSpritePos(_RectPos.x, _RectPos.y);
		m_iLife = 100;
	}
	/*!
	@Destructeur:
	@Permet de d�truire les objets cr��s en m�moire
	*/
	~CWorm(){
		delete m_pSprite;
	}
	/*!
	@M�thode:
	@ReactToExplosion
	@Permet de calculer les dommages subit par l'explosion
	*/
	float ReactToExplosion(CEntity* _pEntity){
<<<<<<< HEAD
		//To do
=======
		return 0.f;
>>>>>>> 620d262c90c1eaa43e43336d6e0d57479837c984
	}

	/*!
	@method HandleEvent
	@param _Evant : Un SDL_Event pour traiter les evenement
	@return null
	*/
	void HandleEvent(SDL_Event _Event){

		switch (_Event.type){

		case SDLK_UP:
		case SDLK_w:
			//To do
			break;
		case SDLK_LEFT:
		case SDLK_a:
			//To do
			break;
		case SDLK_RIGHT:
		case SDLK_d:
			//To do
			break;
		case SDLK_SPACE:
			//To do
			break;
		}
	}

	/*!
	@method Draw
	@param _Renderer : Renderer pour rendre la texture du Sprite 
	@return null
	*/
	void Draw(SDL_Renderer * _Renderer){
		m_pSprite->Render(_Renderer);
	}


	/*!
	@Accesseurs:
	*/

	void SetLife(int _iLifeActuelle){
		m_iLife = _iLifeActuelle;
	}

	void setName(string _Name){ m_strName = _Name; }

	string getName(){ return m_strName; }

};

#endif