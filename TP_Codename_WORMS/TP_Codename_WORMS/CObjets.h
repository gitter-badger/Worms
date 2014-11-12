#ifndef TP_Codename_WORMS_CObjets_h
#define TP_Codename_WORMS_CObjets_h


/*!
@CGrenades
@Classe permettant la cr�ation d'une grenade
*/
class CObjets : public CEntity{
protected:
	//Donn�es membres:
	int m_iRayon; //Donn�e repr�sentant la longueur du rayon de l'explosion.

public:
	/*!
	@Constructeur
	@Description: Permet d'initialiser les donn�es membres
	 @param _iRayon : le rayon d'explosion
	 @param _Name : le nom de l'entit�e
	 @param _uiMasse : la masse de l'entit�e
	 @param _RectPos : le rect de l'entit�e
	@Classe h�ritant de CEntity, elle prend donc les param�tres de CEntity.
	*/
	CObjets(int _iRayon, const char* _Name, SDL_Rect _RectPos) :CEntity(_Name,_RectPos){
		m_iRayon = _iRayon;
	}
	/*!
	@Destructeur:
	@Permet de d�truire les objets cr��s en m�moire
	*/
	~CObjets(){
	}

	/*!
	@method Draw
	@brief Fonction virtuel pour dessiner l'entit�e sur un Renderer
	@param _Renderer : Le renderer sur lequel dessiner
	@return Aucun
	*/
	virtual void Draw(SDL_Renderer* _Renderer){};


	/*!
	@Accesseurs:
	*/
	int getRayon(){
		return m_iRayon;
	}

};

#endif
