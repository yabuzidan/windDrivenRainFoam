PtrList<volVectorField> Urain(phases.size());
PtrList<surfaceScalarField> phirain(phases.size());
PtrList<volScalarField> alpharain(phases.size());

PtrList<volScalarField> scr(phases.size());

forAll(phases, phase_no)
{ 
    word nameU_i ("U" + name(phase_no+1));
    Urain.set
    (
    phase_no,
    new volVectorField 
    (
        IOobject
        (
            nameU_i,
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    )
    );

    word namephi_i ("phi" + name(phase_no+1));
    phirain.set
    (
    phase_no,
    new surfaceScalarField 
    (
        IOobject
        (
            namephi_i,
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::NO_WRITE
        ),
        linearInterpolate(Urain[phase_no]) & mesh.Sf()
    )
    );

    word namealpha_i ("alpha" + name(phase_no+1));
    alpharain.set
    (
    phase_no,
    new volScalarField 
    (
        IOobject
        (
            namealpha_i,
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    )
    );
}
