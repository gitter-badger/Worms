#ifndef TP_Codename_WORMS_CObjets_h
#define TP_Codename_WORMS_CObjets_h


/*!
@CObjets
@Classe permettant la cr�ation d'un objet.
*/
class CObjets : public CEntity{
protected:
	//Donn�es membres:
	

public:

	/*!
	@method Constructeur.
	@brief Initialise les donn�es membres.
	@param _iRayon : le rayon d'explosion
	@param _RectPos : le rect de l'objet
	@return Adresse m�moire de l'objet.
	@discussion Classe h�ritant de CEntity, elle prend donc les param�tres de CEntity.
	*/
	CObjets(SDL_Rect _RectPos, SDL_Texture* _Texture, CExplosion* _Explosion) :CEntity(_RectPos, _Texture, _Explosion){
		
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
	virtual void Draw(SDL_Renderer*){};

	/*!
	@Accesseur virtuel IsItExploded
	@brief Permet de savoir si l'objet est explos� ou non.
	@return bool.
	*/
	virtual bool IsExploded(){return m_boIsexploded;}
	virtual bool HasExploded(){return m_boHasExplosed;}
	virtual void Detonate(){}
	virtual bool isCarePackage(){ return false;}
	CExplosion* getExplosion(){return m_pExplosion;}
	virtual void setExplosion(bool _boSet){
		m_boIsexploded = _boSet;
	}
};

#endif
