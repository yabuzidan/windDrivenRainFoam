PtrList<volScalarField> Ctrain;
Ctrain.setSize(phases.size());    
for (int phase_no = 0; phase_no < phases.size(); phase_no++)
{
    string phase_Ctname = "Ct";
    string phase_no_str;         
    std::stringstream convert;
    convert << phase_no+1;
    phase_no_str = convert.str();
    phase_Ctname.append(phase_no_str);
    
    volScalarField Cttemp
    (
        IOobject
        (
            phase_Ctname,
            runTime.timeName(),
            mesh,
            IOobject::READ_IF_PRESENT,
            IOobject::NO_WRITE
        ),
        mesh,
        dimensionedScalar(phase_Ctname,dimensionSet(0,0,0,0,0,0,0),0)
    );
    Ctrain.set(phase_no,Cttemp);
}

volScalarField k
(
    IOobject
    (
        "k",
        "0",//runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("k",dimensionSet(0,2,-2,0,0,0,0),0)
);
k = k*pow(scalingFactor,2);
k.correctBoundaryConditions();

volScalarField epsilon
(
    IOobject
    (
        "epsilon",
        "0",//runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("epsilon",dimensionSet(0,2,-3,0,0,0,0),0)
);
epsilon = epsilon*pow(scalingFactor,3);
epsilon.correctBoundaryConditions();

volScalarField nut
(
    IOobject
    (
        "nut",
        "0",//runTime.timeName(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE
    ),
    mesh,
    dimensionedScalar("nut",dimensionSet(0,2,-1,0,0,0,0),0)
);
nut = nut*scalingFactor;
nut.correctBoundaryConditions();

volScalarField nutrain
(
IOobject
(
    "nutrain",
    runTime.timeName(),
    mesh,
    IOobject::NO_READ,
    IOobject::NO_WRITE
),
mesh,
dimensionedScalar("nutrain",dimensionSet(0,2,-1,0,0,0,0),0)
);

volScalarField tp
(
IOobject
(
    "tp",
    runTime.timeName(),
    mesh,
    IOobject::NO_READ,
    IOobject::NO_WRITE
),
mesh,
dimensionedScalar("tp",dimensionSet(0,0,1,0,0,0,0),0)
);

volScalarField tfl
(
IOobject
(
    "tfl",
    runTime.timeName(),
    mesh,
    IOobject::NO_READ,
    IOobject::NO_WRITE
),
mesh,
dimensionedScalar("tfl",dimensionSet(0,0,1,0,0,0,0),0)
);
