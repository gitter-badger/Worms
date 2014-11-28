#ifndef TP_Codename_WORMS_CJetPack_h
#define TP_Codename_WORMS_CJetPack_h

/* Liste de chose TOO DOOO :
-Afficher la barre de gaz

/*!
@CJetPack
@Classe permettant l'affichage et l'utilisation du JetPack
*/
class CJetPack{
private:
	//Donn�es membres:
	SDL_Rect m_RectWorm;
	SDL_Rect m_RectSurface; //La pos du rectangle de la surface de la barre de gaz
	SDL_Texture* m_pTexture; // Texture de l'image � afficher.
	CPowerBar* m_pBarreGaz; // Surface de la barre de lancement.
	bool boBarreGaz; // Bool�en pour v�rifier si la barre de lancement sera afficher
	double m_iAngle;
	double m_iNorme;
	C2DVector* m_pVecteur;
	CTimer* m_pTimer;


public:

	/*!
	@Constructeur
	@Description: Permet d'initialiser les donn�es membres
	@param _ix _iy : la pos du jet pack (� modifier pour la pos du worms)
	@param _pTexture : texture de l'image � afficher.
	*/
	CJetPack(int _ix, int _iy, SDL_Rect _RectWorm){ // La position du jet pack devra �tre remplacer par la position du worms
		m_RectSurface = _RectWorm;
		m_RectWorm = _RectWorm;
		m_pBarreGaz = new CPowerBar(m_RectSurface);
		m_pBarreGaz->setPowerLevel(100);
		m_iAngle = 0;
		m_iNorme = 20;
		m_pVecteur = new C2DVector(m_iNorme, m_iAngle, _ix, _iy);
		boBarreGaz = false;
		m_pTimer = new CTimer();
		m_pTimer->SetTimer(100);

	}

	/*!
	@Destructeur:
	@Permet de d�truire les objets cr��s en m�moire
	*/
	~CJetPack(){
	}

	/*!
	@methodRender
	@param _pRenderer : Renderer pour rendre la texture du jet Pack
	@return null
	*/
	void Render(SDL_Renderer* _pRenderer){
		m_pBarreGaz->Draw(_pRenderer);
	}


	void Deplacer(SDL_Rect _RectPosInitiale, double _Angle){
		_RectPosInitiale.x += m_iNorme * cos(_Angle);
		_RectPosInitiale.y += m_iNorme * sin(_Angle);
		m_RectWorm = _RectPosInitiale;
	}
	/*!
	@method HandleEvent
	@param _Event : Un SDL_Event pour traiter les evenement
	@return null
	*/
	void HandleEvent(SDL_Event* _Event){
		switch (_Event->key.keysym.sym){
		case SDLK_LEFT:
			if (!m_pTimer->hasStarted()){
				m_pTimer->Start();
			}
			Deplacer(m_RectWorm, (M_PI));
			if (m_pTimer->IsElapsed()){
				if (m_pBarreGaz->getPower() != 0){
					m_pBarreGaz->PowerDown();
					m_pTimer->Start();
				}
			}
			cout << "mouvement gauche " << m_pBarreGaz->getPower() << " " << m_RectWorm.x << " " << m_RectWorm.y << endl;

			break;

		case SDLK_UP:
			if (!m_pTimer->hasStarted()){
				m_pTimer->Start();
			}

			Deplacer(m_RectWorm, (M_PI / 2));
			if (m_pTimer->IsElapsed()){
				if (m_pBarreGaz->getPower() != 0){
					m_pBarreGaz->PowerDown();
					m_pTimer->Start();
				}
			}
			cout << "mouvement haut " << m_pBarreGaz->getPower() << " " << m_RectWorm.x << " " << m_RectWorm.y << endl;
			break;
		case SDLK_RIGHT:
			if (!m_pTimer->hasStarted()){
				m_pTimer->Start();
			}
			Deplacer(m_RectWorm, 0);
			if (m_pTimer->IsElapsed()){
				if (m_pBarreGaz->getPower() != 0){
					m_pBarreGaz->PowerDown();
					m_pTimer->Start();
				}
			}
			cout << "mouvement droite " << m_pBarreGaz->getPower() << " " << m_RectWorm.x << " " << m_RectWorm.y << endl;
			break;

		}
	}


};

#endif