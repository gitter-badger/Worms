#ifndef TP_Codename_WORMS_CGrenades_h
#define TP_Codename_WORMS_CGrenades_h


/*!
@CGrenades
@Classe permettant la cr�ation d'une grenade
*/
class CGrenades : public CObjets{
private:
	//Donn�es membres:
	CTimer* m_pTimer;	// D�claration d'une nouvelle minuterie pour le temps � �couler avant l'explosion.
	bool boIsexploded;	// Donn�e repr�sentant si l'objet est explos� (true) ou non (false)

public:

	/*!
	@method Constructeur.
	@brief Initialise les donn�es membres.
	@param _iRayon: le rayond d'explosion de l'objetole.
	@param _RectPos: la pos du rectangle de l'objet
	@param _pTexture : texture de l'image � afficher	@return Adresse m�moire de l'objet.
	@discussion Classe h�ritant de CObjets, elle prend donc les param�tres du constructeur CObjets.
	*/
	CGrenades(SDL_Texture* _textureExplosion, SDL_Rect _RectPos, SDL_Texture* _Texture) :CObjets(_textureExplosion, _RectPos, _Texture){
		m_pTimer = new CTimer();
		m_pTimer->SetTimer(1000);
		m_pTimer->Start();
		boIsexploded = false;
	}

	/*!
	@method Destructeur.
	@brief Destroy.
	@discussion He is dead.
	*/
	~CGrenades(){
		delete m_pTimer;
	}

	/*!
	@method Draw
	@param _Renderer : Renderer pour rendre le sprite de la grenade
	@return null
	*/
	void Draw(SDL_Renderer* _pRenderer){
		SDL_RenderCopy(_pRenderer, m_pTexture, NULL, &m_RectPosition);
	}

	/*!
	@method HandleEvent
	@param _Event : Un SDL_Event pour traiter les evenement
	@return null
	*/
	void HandleEvent(SDL_Event _Event){
		m_boFocus = true;
		if (m_pTimer->IsElapsed())
			boIsexploded = true;
	}

	/*!
	@M�thode:
	@ReactToExplosion
	@Permet de calculer les dommages subit par l'explosion
	*/
	void ReactToExplosion(int _iX, int _iY, int _iRayon){}

	/*!
	@method Acesseurs
	@brief Servent a acceder/modifier aux donn�es membres.
	*/

	bool IsItexploded(){
		return boIsexploded;
	}

	void setExplosion(bool _boSet){
		boIsexploded = _boSet;
	}

	void setPos(int _ix, int _iy){
		m_RectPosition.x = _ix;
		m_RectPosition.y = _iy;
	}


	
	void Move(){
		switch (m_EntityState){
		case Immobile:
			if (m_Trajectoire->GetInitSpeed())
				m_Trajectoire->WipeOut();
			break;
		case Chute:
			m_Trajectoire->UpdatePosition();

			CPosition* temp = CPhysics::VerifyNextPosition(m_Trajectoire, m_RectPosition);
			if (temp != nullptr)
			{
				if ((temp->getX() != (int)m_Trajectoire->getNextPos()->getX()) || (temp->getY() != (int)m_Trajectoire->getNextPos()->getY()))
					if (m_Trajectoire->GetActualSpeed()->getNorme() < 200)
						m_EntityState = Immobile;
					else {
						SDL_Rect* Impact = new SDL_Rect({ m_RectPosition.x, m_RectPosition.y + m_RectPosition.h, m_RectPosition.w, 50 });
						m_Trajectoire->Bounce(CPhysics::EvaluateSlope(Impact));
						delete Impact;
						/*
						int iCollision = CPhysics::VerifyGroundCollision(m_RectPosition);
						if (iCollision != NOCONTACT){
							if (iCollision == GROUND){
								SDL_Rect* Impact = new SDL_Rect({ m_RectPosition.x, m_RectPosition.y + m_RectPosition.h, m_RectPosition.w, 50 });
								m_Trajectoire->Bounce(CPhysics::EvaluateSlope(Impact));
								delete Impact;
							}
						}
						*/
					}
				else
					m_EntityState = Chute;

				m_RectPosition.y = temp->getY();
				m_RectPosition.x = temp->getX();
				delete temp;
			}
			else{
				m_RectPosition.x = m_Trajectoire->GetActualPosition()->getX();
				m_RectPosition.y = m_Trajectoire->GetActualPosition()->getY();
			}
			break;
		}
		/*
		int iCollision = CPhysics::VerifyGroundCollision(m_RectPosition);
		if (iCollision != NOCONTACT){
			if (iCollision == GROUND){
				SDL_Rect* Impact = new SDL_Rect({ m_RectPosition.x, m_RectPosition.y + m_RectPosition.h, m_RectPosition.w, 50});
				m_Trajectoire->Bounce(CPhysics::EvaluateSlope(Impact));
				delete Impact;
			}
		}
		m_Trajectoire->UpdatePosition();
		int iX = m_Trajectoire->GetActualPosition()->getX();
		int iY = m_Trajectoire->GetActualPosition()->getY();
		m_RectPosition.x = iX;
		m_RectPosition.y = iY;
		*/
	}

};

#endif
