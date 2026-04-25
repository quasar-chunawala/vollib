#include <memory>
#include <optional>
#include <vector>
#include <ranges>
#include <functional>


class Points2D{
    public:
    Points2D() = default;
    Points2D(const Points2D& other) = delete;
    Points2D(Points2D&& other) = default;
    Points2D& operator=(Points2D&& other) = default;

    Points2D(const std::vector<double>& xvalues, const std::vector<double>& yvalues);

    std::vector<double> getXValues();
    std::vector<double> getYValues();
    const std::vector<double> getXValues() const;
    const std::vector<double> getYValues() const;
    void setInterpolator(std::function<double(const Points2D&, double)>&& interpolator);
    std::optional<std::function<double(const Points2D&, double)>> tryGetInterpolator();
    std::function<double(const Points2D&, double)> getInterpolator();

    private:
    std::vector<double> m_xvalues;
    std::vector<double> m_yvalues;
    std::optional<std::function<double(const Points2D&, double)>> m_interpolator;
};