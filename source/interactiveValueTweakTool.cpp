// softTransformationTool.cpp: implementation of the softTransformationTool class.
//
//////////////////////////////////////////////////////////////////////

#include "interactiveValueTweakTool.h"





//hier befinden sich die definitionen zu allen befehlen

//******************************************************************************************************************
//***************************
//softT contextCommand
//***************************
//***************************************

MPxContext * interactiveValueTweakCtxCommand::makeObj()
{
	context = new interactiveValueTweakCtx;
	return context;

}

//-------------------------------------------------------------
void*		interactiveValueTweakCtxCommand::creator()
//-------------------------------------------------------------
{
	return new interactiveValueTweakCtxCommand;
}

/*
//-------------------------------------------------------------
MStatus		interactiveValueTweakCtxCommand::appendSyntax()
//-------------------------------------------------------------
{
	MSyntax mySyntax = syntax();

	mySyntax.addFlag("ft","falloffType", MSyntax::kString);
	mySyntax.addFlag("uld","useLastDistance", MSyntax::kBoolean);
	mySyntax.addFlag("vf","visualize", MSyntax::kBoolean);
	mySyntax.addFlag("nir","normalIsRelative", MSyntax::kBoolean);
	mySyntax.addFlag("rdc","relativeDistanceChange", MSyntax::kDouble);
	mySyntax.addFlag("rmc","relativeMaskChange", MSyntax::kLong);

	return MS::kSuccess;
}

//-------------------------------------------------------------
MStatus		softTransformationToolCtxCommand::doEditFlags()
//-------------------------------------------------------------
{
	MArgParser argData = parser();
	MString str;

	if(argData.isFlagSet("ft"))
	{
		argData.getFlagArgument("ft",0,str);
		
		if(str == "linear")
			context->fType = 0;
		else if(str == "smooth")
			context->fType = 1;
		else if(str == "spike")
			context->fType = 2;
		else if(str == "dome")
			context->fType = 3;
		else
			context->fType = 0;
	}

	if(argData.isFlagSet("uld"))
	{
		bool arg;
		argData.getFlagArgument("uld",0,arg);
		context->useLastDistance = arg;
	}

	if(argData.isFlagSet("vf"))
	{
		bool arg;
		argData.getFlagArgument("vf",0,arg);
		context->fVis = arg;
	}

	if(argData.isFlagSet("nir"))
	{
		bool arg;
		argData.getFlagArgument("nir",0,arg);
		context->nirFlag = arg;
	}
	
	if(argData.isFlagSet("rdc"))
	{
		double arg;
		argData.getFlagArgument("rdc",0,arg);
		if(!context->changeDistance(arg))
			MGlobal::displayWarning("You cannot change the distance as long the manipulator doesn't show up");
	}

	if(argData.isFlagSet("rmc"))
	{
		int arg;
		argData.getFlagArgument("rmc",0,arg);
		if(!context->changeMask(arg))
			MGlobal::displayWarning("You cannot change the maskSize as long the manipulator doesn't show up");
	}

	return MS::kSuccess;

}

//-------------------------------------------------------------
MStatus		softTransformationToolCtxCommand::doQueryFlags()
//-------------------------------------------------------------
{
	setResult(MString("Not implemented"));
	return MS::kSuccess;
}
*/


//******************************************************************************************************************
//*********************************
//MPX_TOOL_COMMAND METHODEN
//*********************************
//******************************************************************************************************************


//-------------------------------------------------------------
void* interactiveValueTweakCmd::creator()
//-------------------------------------------------------------
{
	return new interactiveValueTweakCmd;
}



//-------------------------------------------------------------
MStatus interactiveValueTweakCmd::finalize()
//-------------------------------------------------------------
{
	MArgList	command;
	command.addArg(MString("InteraciveTweakValueTool"));

	return	MPxToolCommand::doFinalize(command);
}


//------------------------------------------------------------
MStatus interactiveValueTweakCmd::doIt(const MArgList &args)
//------------------------------------------------------------
{	
	return MS::kSuccess;
}

//------------------------------------------------------------
MStatus	interactiveValueTweakCmd::undoIt()
//------------------------------------------------------------
{
	return	MS::kSuccess;
}

//------------------------------------------------------------
MStatus	interactiveValueTweakCmd::redoIt()
//------------------------------------------------------------
{
	return	MS::kSuccess;
}


//------------------------------------------------------------
bool	interactiveValueTweakCmd::isUndoable() const
//------------------------------------------------------------
{
	return false;
}



//******************************************************************************************************************
//*********************************
//MPX_SELECTION_CONTEXT METHODEN
//*********************************
//******************************************************************************************************************

//------------------------------------------------------------
interactiveValueTweakCtx::interactiveValueTweakCtx():isValidSession(true), ui(0)
//------------------------------------------------------------
{
	setTitleString("interactiveValueTweakTool");
}


//--------------------------------------------------------------------------
void interactiveValueTweakCtx::getValues()
//--------------------------------------------------------------------------
{
	MFnNumericAttribute numAttrFn;
	MFnEnumAttribute	enumAttr;
	
	attrValues.clear();
	
	


	for(unsigned int i = 0; i < keyables.length();i++)
	{
		MObject attr = keyables[i].attribute();


		if(attr.apiType() == MFn::kNumericAttribute)
		{

			numAttrFn.setObject(attr);			

			if(numAttrFn.unitType() == MFnNumericData::kDouble)
			{
				double value;
				keyables[i].getValue(value);
				
				MString valueStr;valueStr = value;
				attrValues.append(valueStr);

			}
			else if(numAttrFn.unitType() == MFnNumericData::k3Double)
			{
				//code zum bearbeiten dieses FAlles hinzufügen
			}
			else
			{
				attrValues.append("unsupported");
			}

		}
		else if(attr.apiType() == MFn::kEnumAttribute)
		{
			enumAttr.setObject(attr);

			short value;
			keyables[i].getValue(value);

			attrValues.append(enumAttr.fieldName(value));
		}
		else
		{
			attrValues.append("unsupported");
		}
	}


}

//--------------------------------------------------------------------------
void interactiveValueTweakCtx::toolOnSetup(MEvent &)
//--------------------------------------------------------------------------
{
    setHelpString("Select a node to display its parameters");

	//arrays säubern von letztem aufruf
	keyables.clear();
	attrNames.clear();
	attrValues.clear();
	isValidSession = false;
	
	MStatus stat;

	MSelectionList selection;
	//selection durchsuchen nach meshNode oder kPluginDepNode (BPTNode)
	MGlobal::getActiveSelectionList(selection);

	MItSelectionList	selIter(selection, MFn::kPluginDependNode);
	MDagPath			meshPath;
	MObject				node;

	bool	meshFound, BPTNodeFound;
	meshFound = BPTNodeFound = false;

	for(;!selIter.isDone();selIter.next())
	{
		selIter.getDependNode(node);
		BPTNodeFound = true;
		isValidSession = true;
		break;
	}

	
	if( !BPTNodeFound )
	{
		//auf meshes überprüfen
		selIter.setFilter(MFn::kMesh);
		selIter.reset();	

		for(;!selIter.isDone();selIter.next())
		{
			selIter.getDagPath(meshPath);
			meshFound = true;
			break;
		}
		
		if(meshFound)
		{
			//versuchen, den input von inMesh zu bekommen
			meshPath.extendToShape();
			MFnDependencyNode depNodeFn(meshPath.node());


			MPlug inMeshPlug = depNodeFn.findPlug("inMesh",&stat);

			if(stat == MS::kFailure)
			{
				isValidSession = false;
			}
			else
			{
				if(inMeshPlug.isConnected())
				{
					MPlugArray connections;
					
					inMeshPlug.connectedTo(connections,true, false);

					
					node = connections[0].node();
					isValidSession = true;
				}
				else
					isValidSession = false;
			}

		}
		else
			isValidSession = false;
	}


	if(isValidSession)
	{
	
		//Namen der keybaren Attribute auslesen 
		MFnDependencyNode	depNodeFn(node);
		
		int count = depNodeFn.attributeCount();
		
		
		int i;
		for(i = 0; i < count;i++)
		{
			MPlug tmpPlug(node,depNodeFn.attribute(i));
			
			if(tmpPlug.isKeyable())
			{
				keyables.append(tmpPlug);
			}

		}

		//erster Slot in array ist reserviert für den Namen der Node
		attrNames.append(depNodeFn.name());

		if(keyables.length() != 0)
		{
			//attribut Namen eintragen
			for(i = 0; i < keyables.length(); i++)
			{

				attrNames.append(keyables[i].partialName(false,false,false,false,true));
				//attrNames.append(keyables[i].name());
			}
			
			//attribut Werte holen
			getValues();
			
		}
		else
		{
			attrNames.append("No keyable attributes found");
			attrValues.append("");
		}

	}
	else
	{//entsprechende Arrays	erstellen für den locator, die aber leer sind
		
		//name
		attrNames.append("None");
		attrNames.append("No Attributes");
		attrValues.append("");

	}


	// Jetzt erstmal testweise eine kleine Box erzeugen
	//
	ui = new UI_container();
	//UI_container ui;
	

	// PositionTest
	//
	//ui->setStaticAbsMode(point(150,150));

	ui->setStaticRelMode( 0.5,0.5, BInput::getGlRect() );



	MFnDependencyNode	depFn(meshPath.node());

	/*MPlug worldMat = depFn.findPlug("worldMatrix");

	worldMat = worldMat.elementByLogicalIndex(0);


	ui->set3dMode(worldMat, offsetMatrix(-60, 0));
	*/


//	ui->addElement( new UI_textBox("Hello My first Button", UI_textBox::kStatic) );
	//

	
	// Mal einen Slider testen
	//
	UI_generalSlider<double>* slider = new UI_generalSlider<double>(true);
	
	depFn.setObject( meshPath.transform() );
	MPlug tx = depFn.findPlug("translateX");

	INVIS( if( tx.isNull() ) cout<<" Plug TX WAR 0!!"<<endl; );

	slider->setPlug(tx);

	ui->addElement( slider );

	


/*
	slider = new UI_sliderHorizontal();

	tx = depFn.findPlug("translateY");

	slider->setPlug( tx );

	ui->addElement( slider );

	UI_textBox* tb = new UI_textBox("MeinErsterButton");
	ui->addElement( tb );
*/
	//ui->draw();
	//ui->draw();


	//debug
	INVIS(		\
	UINT i	;	\
	for(i = 0; i < attrNames.length(); i++)	\
		cout<<attrNames[i].asChar()<<endl;			\
													\
													\
	for(i = 0; i < attrValues.length(); i++)\
		cout<<attrValues[i].asChar()<<endl;\
	);


}

//------------------------------------------------------------
void interactiveValueTweakCtx::toolOffCleanup()
//------------------------------------------------------------
{
	// Container ptr l�schen
	// UI kann eigentlich nicht 0 sein
	//
	if( ui != 0)
	{
		// Vorher muss clear gerufen werden, sonst gibts memoryLecks - wird jetzt vom destructor gemacht
		//
		

		delete ui;
		ui = 0;
	}


	MPxContext::toolOffCleanup();
}


//------------------------------------------------------------
MStatus interactiveValueTweakCtx::doPress(MEvent &event)
//------------------------------------------------------------
{
	MStatus stat;

	MPRINT("Bin in DoPress")

    // If we are not in selecting mode (i.e. an object has been selected)
    // then set up for the translation.
    

    view = M3dView::active3dView();
	

    return stat;
}

//------------------------------------------------------------
MStatus interactiveValueTweakCtx::doDrag(MEvent & event)
//------------------------------------------------------------
{
    MStatus stat;

             
	view.refresh(true);
    
    return stat;
}

//------------------------------------------------------------
MStatus interactiveValueTweakCtx::doRelease(MEvent &event)
//------------------------------------------------------------
{



	

	setHelpString(MString("Help"));

	view.refresh(true);
    return MS::kSuccess;
}


//------------------------------------------------------------
MStatus interactiveValueTweakCtx::doEnterRegion(MEvent &event)
//------------------------------------------------------------
{
    return setHelpString(MString("Help"));
}
