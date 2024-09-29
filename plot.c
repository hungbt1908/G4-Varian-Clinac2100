void plot()
{
    gROOT->Reset();
    gROOT->SetStyle("Plain");
    TFile *f = new TFile("output.root", "READ");
    f->ls();

    TTree *tree = (TTree *)f->Get("PrimaryVertex;1");
    tree->Print();

    double xPos, yPos, zPos, xDir, yDir, zDir, kinetic, phi, theta;
    int nEvents;
    int entries = tree->GetEntries();

    tree->SetBranchAddress("xPos", &xPos);
    tree->SetBranchAddress("yPos", &yPos);
    tree->SetBranchAddress("zPos", &zPos);
    tree->SetBranchAddress("xDir", &xDir);
    tree->SetBranchAddress("yDir", &yDir);
    tree->SetBranchAddress("zDir", &zDir);
    tree->SetBranchAddress("kinetic", &kinetic);

    TH2D *xy2DHits = new TH2D("XY plane", "Source X-Y distribution", 400, -2.0, 2.0, 400, -2.0, 2.0);
    TH1D *kineticHist = new TH1D("Kinetic", "Kinetic (MeV)", 1000, 5.4, 6.4);
    TH2D *histoEmittanceXTheta = new TH2D("histoEmittanceXTheta", "Emittance X #theta", 1000, -2.0, 2.0, 1000, -5.0, 5.0);
    TH2D *histoEmittanceYPhi = new TH2D("histoEmittanceZPhi", "Emittance Y #phi", 1000, -2.0, 2.0, 1000, -5.0, 5.0);
    // TH1D *thetaHist = new TH1D("theta", "#theta distribution (deg)", 180, -180, 180);

    for (int i = 0; i < entries; i++)
    {
        tree->GetEntry(i);
        if (1)
        {
            xy2DHits->Fill(xPos, yPos, 1);
            kineticHist->Fill(kinetic, 1);
            histoEmittanceXTheta->Fill(xPos, atan(xDir / zDir) * 1000., 1); // x-axis in mm and z-axis in mrad
            histoEmittanceYPhi->Fill(yPos, atan(yDir / zDir) * 1000, 1);
            // thetaHist->Fill(theta * 180 / 3.14, 1);
        }
    }

    // Define a canvas and set the dimension
    Double_t w = 1200;
    Double_t h = 800;
    TCanvas *c1 = new TCanvas("canvas", "fefe", w, h);
    c1->SetWindowSize(w + (w - c1->GetWw()), h + (h - c1->GetWh())); // set dimension
    c1->Divide(2, 2);

    // sub-plot set-up
    c1->cd(1);
    xy2DHits->Draw("COLZ");

    c1->cd(2);
    kineticHist->Draw();

    c1->cd(3);
    histoEmittanceXTheta->Draw("COLZ");
    // thetaHist->Draw();

    c1->cd(4);
    histoEmittanceYPhi->Draw("COLZ");
}