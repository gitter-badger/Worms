#ifndef TP_Codename_WORMS_CCaisses_h
#define TP_Codename_WORMS_CCaisses_h


/*!
@CCaisses
@Classe permettant la cr�ation d'une caisse
*/
class CCaisses : public CObjets{
private:
	//Donn�es membres:
	SDL_Texture* m_pTexture; // Texture de l'image � afficher.
public:
	/*!
	@Constructeur
	@Description: Permet d'initialiser les donn�es membres
	 @param _Name : le nom de l'objet
	 @param _uiMasse: la masse de l'objet
	 @param _RectPos: la pos du rectangle de l'objet
	 @param _pTexture : texture de l'image � afficher
	@Classe h�ritant de CObjets, elle prend donc les param�tres du constructeur CObjets
	*/
<<<<<<< HEAD
	CCaisses(int _iRayon, SDL_Rect _RectPos, SDL_Texture* _pTexture) :CObjets(_iRayon, _RectPos){
		m_pTexture = _pTexture;
=======
	CCaisses(const char* _Name, unsigned int _uiMasse, SDL_Rect _RectPos) : CObjets(_Name, _uiMasse, _RectPos){
>>>>>>> 620d262c90c1eaa43e43336d6e0d57479837c984
	}



	/*!
	@method Draw
	@param _Renderer : Renderer pour rendre le textures du Sprite et du texte du bouton
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
		// TO do
	}

	/*!
	@Destructeur:
	@Permet de d�truire les objets cr��s en m�moire
	*/
	~CCaisses(){
	}



	/*!
	@Accesseurs:
	*/
	
	void setPos(int _ix, int _iy){
		m_RectPosition.x = _ix;
		m_RectPosition.y = _iy;
	}

};

#endif