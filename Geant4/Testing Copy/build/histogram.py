import ROOT
canvas = ROOT.TCanvas("canvas", "Histogram", 1600, 900)
histogram = ROOT.TH1F("histogram", "Plot of Frequency vs Energy (MeV)", 500, 0, 0.01)

histogram.SetXTitle("Energy (MeV)")
histogram.SetYTitle("Frequency")
histogram.SetLineColor(ROOT.kRed)



file = open("output_1GeV.txt", "r")


i=0
count=0
for line in file:
    value = float(line.strip())
    i=i+value
    count+=1
    histogram.Fill(value)
file.close()


integral = histogram.Integral()
histogram.Scale(1/integral)


landau_func = ROOT.TF1("landau_func", "landau", histogram.GetXaxis().GetXmin(), histogram.GetXaxis().GetXmax())

    # Set initial parameter values if needed
    # landau_func.SetParameters(initial_parameters)


histogram.Fit(landau_func, "R")


fit_result = histogram.GetFunction("landau_func")

mpv = fit_result.GetParameter(1)
sigma = fit_result.GetParameter(2)
print("Fit Parameters:")
print("MPV:", mpv)
print("Sigma:", sigma)


histogram.Draw()
canvas.Update()
ROOT.gApplication.Run()
