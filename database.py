from sqlalchemy import create_engine, Column, Integer, String, ForeignKey
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy.orm import relationship, sessionmaker

Base = declarative_base()

class Character(Base):
    __tablename__ = 'characters'
    id = Column(Integer, primary_key=True)
    name = Column(String)
    age = Column(Integer)
    attributes = Column(String)
    parent_id = Column(Integer, ForeignKey('characters.id'))
    children = relationship("Character", backref='parent', remote_side=[id])

engine = create_engine('sqlite:///ai_characters.db')
Base.metadata.create_all(engine)
Session = sessionmaker(bind=engine)
session = Session()

def add_character(name, age, attributes, parent_id=None):
    new_character = Character(name=name, age=age, attributes=attributes, parent_id=parent_id)
    session.add(new_character)
    session.commit()

def get_character(id):
    return session.query(Character).filter_by(id=id).first()

def get_all_characters():
    return session.query(Character).all()

