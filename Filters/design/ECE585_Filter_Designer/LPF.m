function [L,C,R,err] = LPF(G,w,R0,first)

%This function does the LPF transformation for a given frequency & topology
%The variable first is 0 for c-first topology & 1 for l-first

L = zeros(length(G)-1,1);
C = zeros(length(G)-1,1);
err = '';
anstxt = "";

if(isempty(G)||isempty(w)||isempty(first)||isempty(R0))
   err = 'Not enough parameters entered';
   return
end

for ii=1:(length(G)-1)
    if(mod(ii,2)==first) %calculate inductor value
        L(ii) = (R0*G(ii))/w;
        anstxt = anstxt + sprintf('L%d = %d\n',ii,L(ii));
    else %calculate capacitor value
        C(ii) = G(ii)/(R0*w);
        anstxt = anstxt + sprintf('C%d = %d\n',ii,C(ii));
    end
end

R = G(length(G))*R0;

anstxt = anstxt + sprintf('R = %d\n',R);

questdlg(sprintf('%s',anstxt),'LPF Result','OK','OK');