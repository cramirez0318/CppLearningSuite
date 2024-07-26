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

class ActionLog(Base):
    __tablename__ = 'action_logs'
    id = Column(Integer, primary_key=True)
    action = Column(String)
    character_id = Column(Integer)
    details = Column(String)

engine = create_engine('sqlite:///ai_characters.db')
Base.metadata.create_all(engine)
Session = sessionmaker(bind=engine)
session = Session()

def add_character(name, age, attributes, parent_id=None):
    new_character = Character(name=name, age=age, attributes=attributes, parent_id=parent_id)
    session.add(new_character)
    session.commit()

def character_to_dict(character):
    return {
        'id': character.id,
        'name': character.name,
        'age': character.age,
        'attributes': character.attributes,
        'parent_id': character.parent_id
    }

def get_character(id):
    character = session.query(Character).filter_by(id=id).first()
    return character_to_dict(character) if character else None

def get_all_characters():
    characters = session.query(Character).all()
    return [character_to_dict(character) for character in characters]

def log_action(action, character_id, details):
    new_action = ActionLog(action=action, character_id=character_id, details=details)
    session.add(new_action)
    session.commit()

def undo_action():
    last_action = session.query(ActionLog).order_by(ActionLog.id.desc()).first()
    if last_action:
        if last_action.action == 'add':
            character = session.query(Character).filter_by(id=last_action.character_id).first()
            if character:
                session.delete(character)
        elif last_action.action == 'update':
            details = eval(last_action.details)
            character = session.query(Character).filter_by(id=last_action.character_id).first()
            if character:
                character.name = details['name']
                character.age = details['age']
                character.attributes = details['attributes']
                character.parent_id = details['parent_id']
        session.delete(last_action)
        session.commit()

def redo_action():
    # Implement redo functionality
    pass
